#!/usr/bin/env python # coding: utf-8 # In[ ]: # In[ ]:
import numpy as np
import pandas as pd
import cvxpy as cp

from matplotlib import pyplot as plt


# # Input Format
#
# Consider an undirected graph $G = (V, E)$. Let $n = |V|$ and $m = |E|$ denote the numbers of vertices and edges respectively. Assume WLOG that $V = \{0, 1, 2, \dots, n-1\}$ with $s = 0$ and $t = n-1$. The input specifies $n$ and a list of edges each of which is given by a tuple $(i, j, c)$, i.e., the vertices $i$ and $j$ and the capacity $c$.

# In[ ]:
global iter
iter = 0
global want
want = 1


def test_graph_1():
    return 6, [
        [0, 1, 20],
        [1, 2, 10],
        [1, 3, 10],
        [0, 2, 4],
        [2, 3, 9],
        [2, 4, 14],
        [3, 5, 20],
        [3, 4, 7],
        [4, 5, 4],
    ]


def test_graph_2():
    return 7, [
        [0, 1, 220],
        [0, 2, 54],
        [1, 2, 510],
        [1, 3, 910],
        [2, 3, 90],
        [2, 4, 114],
        [3, 4, 37],
        [3, 5, 120],
        [4, 5, 54],
        [3, 6, 120],
        [2, 6, 310],
        [1, 6, 151],
        [4, 6, 103],
    ]


def test_graph_3():
    return 8, [
        [0, 1, 20],
        [0, 2, 12],
        [0, 3, 19],
        [1, 4, 12],
        [2, 5, 6],
        [3, 6, 8],
        [4, 7, 12],
        [5, 7, 12],
        [6, 7, 11],
    ]


def test_graph_4():
    return 6, [[0, 1, 20], [1, 2, 8], [2, 3, 6], [2, 4, 14], [3, 4, 6], [4, 5, 12]]


def test_graph_5():
    return 14, [
        [0, 1, 20],
        [0, 2, 8],
        [1, 3, 6],
        [1, 4, 19],
        [2, 5, 14],
        [2, 6, 9],
        [3, 7, 13],
        [3, 8, 21],
        [4, 9, 29],
        [4, 10, 12],
        [5, 11, 31],
        [6, 12, 17],
        [7, 13, 5],
        [8, 13, 17],
        [9, 13, 28],
        [10, 13, 10],
        [11, 13, 11],
        [12, 13, 7],
    ]


def test_graph_6():

    return 6, [
        [0, 1, 20],
        [0, 2, 24],
        [1, 3, 19],
        [2, 3, 15],
        [4, 3, 11],
        [2, 4, 14],
        [1, 4, 37],
        [3, 5, 48],
    ]


# In[ ]:


def test_graph_unit_cap():
    return 6, [
        [0, 1, 1],
        [0, 2, 1],
        [1, 2, 1],
        [1, 3, 1],
        #    [2, 3, 1],
        [2, 4, 1],
        [3, 4, 1],
        [3, 5, 1],
        [4, 5, 1],
    ]


# In[ ]:


# n, edge = test_graph_6()
# n, edge = test_graph_unit_cap()
# min_cut = [0,1] for test_graph_1
# min_cut = [0,1] for test_graph_2
# min_cut  = [3,4,5] for test_graph_3
# min_cut = [1] for test_graph_4
# min_cut = [0,1] for test_graph_5


# print('1111') # print(n) # In[ ]:


def electrical_flow(n, res):
    # res is expressed in its inverse
    A = np.zeros([n, n])
    for i, j, r in res:
        A[i, j] = -r
        A[j, i] = -r
        A[i, i] += r
        A[j, j] += r

    A[0, :] = np.zeros(n)
    A[0, 0] = 1.0
    A[n - 1, :] = np.zeros(n)
    A[n - 1, n - 1] = 1.0

    b = np.zeros(n)
    b[0] = 1
    b[n - 1] = 0.0
    # add 1-0 cosntraint to   variable phi
    # qifei
    phi = np.linalg.inv(A) @ b
    # @ operation just work as np.dot
    flow = [[i, j, (phi[i] - phi[j]) * r] for i, j, r in res]
    energy = sum([(phi[i] - phi[j]) ** 2 * r for i, j, r in res])

    return phi, flow, energy


# In[ ]:


# phi, flow, energy = electrical_flow(n, edge)
# print(phi)
# print(flow)
# print("energy:",energy)


# In[ ]:


def update_cvx(phi, edge):
    global epsilon
    x = cp.Variable(len(edge))
    I = np.ones(len(edge))
    objective = 0

    for k in range(len(edge)):
        phi1 = phi[edge[k][0]]
        phi2 = phi[edge[k][1]]
        cap = edge[k][2]
        objective += ((phi1 - phi2) ** 2 * cap ** 2) * cp.inv_pos(x[k])
    # 原来倒数需要用inv_pos
    objective = cp.Minimize(objective)
    constraints = [0.000001 <= x, sum(x) == 1]
    prob = cp.Problem(objective, constraints)
    result = prob.solve()
    # please remember that we can speficy using one index of some variable
    return x.value


def update_accurate(phi, edge):
    global iter 
    epsilon = 0.0001/len(edge)
    iter += 1
    W = sum([abs(phi[i] - phi[j]) * c for i, j, c in edge])
    uc_wets = [1 / W * abs(phi[i] - phi[j]) * c for i, j, c in edge]
    index = [i for i in range(len(uc_wets)) if uc_wets[i] < epsilon]
    pre = []
    while index:
        if pre == index:
            break
        deleted = 0
        for k in index:
            deleted += abs(phi[edge[k][0]] - phi[edge[k][1]]) * edge[k][2]
        W -= deleted
        uc_wets = [
            (1 - len(index) * epsilon) / W * abs(phi[i] - phi[j]) * c
            for i, j, c in edge
        ]
        for k in index:
            uc_wets[k] = epsilon
        # if iter % 10 == 0:
        #   print(iter, index)
        pre = index
        index = [i for i in range(0, len(uc_wets)) if uc_wets[i] <= epsilon]
    # if iter % 10 == 0:
    #   import pdb
    #   pdb.set_trace()

    return uc_wets

    # while min(uc_wets) < epsilon:
    #   index  = uc_wets.index(min(uc_wets))
    #   uc_wets[index]  = epsilon

    # return


# In[ ]:

import math


def altertating_minimization(n, edge, min_cut=[], cut_val=1):
    CAP = 1e8
    m = len(edge)
    # eps = .01/m
    res = [[i, j, m * c ** 2] for i, j, c in edge]
    # zhiyi真的是天才
    previous = None
    previous_phi = None
    data1 = []
    data2 = []
    data3 = []
    data4 = []
    flag = "y"
    for num in range(200):
        phi, flow, energy_changephi = electrical_flow(n, res)
        if data2 != [] and abs(data2[-1] - math.sqrt(energy_changephi)) < 1e-3:
            break
        data2.append(math.sqrt(energy_changephi))
        # capacity_raw = np.zeros(n)
        # residual = 1
        capacity = [x[2] for x in edge]
        weights = update_accurate(phi, edge)
        W = sum([abs(phi[i] - phi[j]) * c for i, j, c in edge])
        # res = [[i, j, min(c * W / abs(phi[i] - phi[j]), CAP)] for i, j, c in edge]
        res = []
        for id in range(0, len(edge)):
          item = [edge[id][0], edge[id][1], edge[id][2]**2/ weights[id]]
          res.append(item)
        nu = 1
        for i in min_cut:
            nu *= weights[i] ** (capacity[i] / cut_val)

        if data4 != [] and flag == "y":
            if nu < data4[-1]:
                flag = "n"
        data4.append(nu)
        # if num != 0:
        #  for i in range(m):
        #  capacity_raw[edge[i][0]] +=  edge[i][2]**2/previous[i]
        #  capacity_raw[edge[i][1]] +=  edge[i][2]**2/previous[i]
        #  for i in range(len(capacity_raw)):
        #  residual  += (phi - previous_phi)[i]**2 *min(capacity_raw)
        #  print("residual : %f" % residual)
        #  print("iterate number: %d" % num)
        #  print("energy :%d" % math.sqrt(energy_changephi))
        #  print("nu:%f" % nu)
        # previous_phi = phi

        # if num % 10 == 0:
        # energy_term1 = [k  for i,j,k in flow if i == 0]
        # energy_term1 = sum(energy_term1)
        # print('=== after round %4d ===' % i)
        # import pdb
        # print('energy_reduced_by_phi= %f' %  ( energy_changeres - energy_changephi))
        # weights = update_cvx(phi, edge)
        #  ans =  (np.array(weights) -  np.array( previous) )@  np.array(congestion)
        #  print("energy_decrease_gradient = %f" % ans )/woshitaincai1

        # capacity = [(1/x[2])**2 for x in edge]
        # resistance = np.array(weights)* np.array(capacity)

        # sss = []
        #
        # for i in range(len(resistance)):
        #  sss.append([edge[i][0],edge[i][1],1/resistance[i]])
        # print('energy = %f' % energy)
        data1.append(phi)
        data3.append(weights)
        # in
        # weight_res = []
        # res = [[i, j, min(c*W/abs(phi[i]-phi[j]), CAP)] for i, j, c in edge]

        # for i in range(len(res)):
        #  a  = 1/res[i][2] * edge[i][2]**2
        #  weight_res.append(a)
        # ex_cut = ( sum(abs(phi[i]-phi[j]) * c for i,j,c in edge))
        # energy_changeres = sum([(phi[i]-phi[j])**2*r for i, j, r in res])
        # energy_changeres2 = sum([(phi[i]-phi[j])**2*r for i, j, r in sss])
        #
        # capacity_raw = np.zeros(n)
        # import pdb
        # pdb.set_trace()

        # previous = weights

        # if num % 1 == 0:
        #   print('energy = %f' %  np.sqrt( energy_changeres))
        #   print('energy2 = %f' %  np.sqrt(energy_changeres2))
        #   print('energy_reduced_by_res : %f' % (-energy_changeres2 + energy_changephi) )
        # #res = [[i, j, c*W/abs(phi[i]-phi[j])] for i, j, c in edge]
        # if i % 10 == 0:
        #     print('=== after round %4d ===' % i)
        #     print('unchanged_energy = %f' %   energy_notchange)
        #     print('energy = %f' % energy)
        #     print('sqrt(energy) = %f' % np.sqrt(energy))

        #     c = max([flow[j][2]/edge[j][2] for j in range(len(edge))])
        # print([flow[j][2]/edge[j][2] for j in range(len(edge))])

    return phi, flow, data1, data2, data3, data4, flag


# In[ ]: j
# phi, flow , data, data2,data3, data4= altertating_minimization(n, edge)
# df = pd.DataFrame(data = data)
# df2 = pd.DataFrame(data = data2)
# df3 = pd.DataFrame(data = data3)
# df4 = pd.DataFrame(data = data4)
# df2.to_excel("energy.xlsx")
# df3.to_excel("weightsj.xlsx")

# df4.to_excel("nu.xlsx")
#
# w_1 = data
# x = [i for i in range(0,len(w_1))]
# w_1 = list(w_1)
#
#
# plt.plot(w_1)
# plt.show()