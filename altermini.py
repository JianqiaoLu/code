#!/usr/bin/env python # coding: utf-8 # In[ ]: # In[ ]:
import math 
import numpy as np
import pandas as pd
import cvxpy as cp

from scipy.sparse.linalg import spsolve

# # Input Format
#
# Consider an undirected graph $G = (V, E)$. Let $n = |V|$ and $m = |E|$ denote the numbers of vertices and edges respectively. Assume WLOG that $V = \{0, 1, 2, \dots, n-1\}$ with $s = 0$ and $t = n-1$. The input specifies $n$ and a list of edges each of which is given by a tuple $(i, j, c)$, i.e., the vertices $i$ and $j$ and the cap $c$.

# In[ ]:
global iter
ter = 0
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

def test_graph_7():
  return 3,[
    [0,1,1],
    [0,1,2],
    [1,2,4],
  ]

def test_graph_8():
  return 3,[
    [0,1,math.sqrt(5)],
    [1,2,2],
  ]


def test_graph_9():
  return 4,[[0,1,2],
    [0,1,2],
    [1,2,10],
    [2,3,2],
  ]

def test_graph_10():
  return 6,[[0,3,1.5],
    [0,4,1],
    [3,1,2],
    [4,1,2],
    [0,1,1.5],
    [1,2,10],
    [2,5,.5],
    [3,5,1],
    [1,5,2.5],
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
# min_cuts = [0,1] for test_graph_1
# min_cuts = [0,1] for test_graph_2
# min_cuts  = [3,4,5] for test_graph_3
# min_cuts = [1] for test_graph_4
# min_cuts = [0,1] for test_graph_5


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
    # phi = spsolve(A, b)
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


def update_w(phi, edge):
    eps_m = 0.0001 / len(edge)
    W = sum([abs(phi[i] - phi[j]) * c for i, j, c in edge])
    e_all = [1 / W * abs(phi[i] - phi[j]) * c for i, j, c in edge]
    e_hat = [i for i in range(len(e_all)) if e_all[i] < eps_m]
    pre = []
    while len(e_hat):
        if pre == e_hat:
            break
        for k in e_hat:
            W -= abs(phi[edge[k][0]] - phi[edge[k][1]]) * edge[k][2]
        e_all = [
            (1 - len(e_hat) * eps_m) / W * abs(phi[i] - phi[j]) * c for i, j, c in edge
        ]
        for k in e_hat:
            e_all[k] = eps_m
        # if iter % 10 == 0:
        #   print(iter, e_hat)
        pre = e_hat
        e_hat = [i for i in range(0, len(e_all)) if e_all[i] <= eps_m]
    # if iter % 10 == 0:
    #   import pdb
    #   pdb.set_trace()

    return e_all

    # while min(uc_wets) < eps_m:
    #   index  = uc_wets.index(min(uc_wets))
    #   uc_wets[index]  = eps_m

    # return


# In[ ]:


def altertating_minimization(n, edge, min_cuts=[], cut_val=1):
    m = len(edge)
    # eps = .01/m
    res = [[i, j, m * c ** 2] for i, j, c in edge]
    
    # zhiyi真的是天才
    data1 = []
    data2 = []
    data3 = []
    data4 = [[] for i in range(len(min_cuts))]
    data5 = [[] for i in range(len(min_cuts))]
    
    flag = "y"
    for ind in range(1000):

        phi, flow, energy = electrical_flow(n, res)
        

        if data2 != [] and abs(data2[-1] - math.sqrt(energy)) < 1e-5:
            break
        # cap_raw = np.zeros(n)
        # residual = 1

        w = update_w(phi, edge)
        res = []

        for id in range(0, len(edge)):
            item = [edge[id][0], edge[id][1], edge[id][2] ** 2 / w[id]]
            res.append(item)

        # cap = [x[2] for x in edge]
        # phi_e = [abs(phi[i[0]] - phi[i[1]]) for i in  edge]
        # cong = [flow[i][2]/cap[i] for i in range(m)] 
        # phi_c = [phi_e[i]*cap[i] for i in range(m)]
        # wtow =  cong /sum(phi_c)
        for j in range(len(min_cuts)):
            nu  = 1
            eta = 0
            for i in min_cuts[j]:
                # nu2 = [cap[i] * math.log(wtow[i]) for i in min_cuts[j]]
                # ans = sum(nu2)/sum(cap)
                nu *= w[i] ** (cap[i] / cut_val)
                eta += w[i]
            if data4[j]!= [] and flag == "y":
                if nu < data4[j][-1]:
                  flag = 'n'
            data4[j].append(nu)
            data5[j].append(eta)
                

        data1.append(phi)
        data2.append(math.sqrt(energy))
        data3.append(w)
        # if num != 0:
        #  for i in range(m):
        #  cap_raw[edge[i][0]] +=  edge[i][2]**2/previous[i]
        #  cap_raw[edge[i][1]] +=  edge[i][2]**2/previous[i]
        #  for i in range(len(cap_raw)):
        #  residual  += (phi - previous_phi)[i]**2 *min(cap_raw)
        #  print("residual : %f" % residual)
        #  print("iterate number: %d" % num)
        #  print("energy :%d" % math.sqrt(energy))
        #  print("nu:%f" % nu)
        # previous_phi = phi

        # if num % 10 == 0:
        # energy_term1 = [k  for i,j,k in flow if i == 0]
        # energy_term1 = sum(energy_term1)
        # print('=== after round %4d ===' % i)
        # import pdb
        # print('energy_reduced_by_phi= %f' %  ( energy_changeres - energy))
        # w = update_cvx(phi, edge)
        #  ans =  (np.array(w) -  np.array( previous) )@  np.array(congestion)
        #  print("energy_decrease_gradient = %f" % ans )/woshitaincai1

        # cap = [(1/x[2])**2 for x in edge]
        # resistance = np.array(w)* np.array(cap)

        # sss = []
        #
        # for i in range(len(resistance)):
        #  sss.append([edge[i][0],edge[i][1],1/resistance[i]])
        # print('energy = %f' % energy)
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
        # cap_raw = np.zeros(n)
        # import pdb
        # pdb.set_trace()

        # previous = w

        # if num % 1 == 0:
        #   print('energy = %f' %  np.sqrt( energy_changeres))
        #   print('energy2 = %f' %  np.sqrt(energy_changeres2))
        #   print('energy_reduced_by_res : %f' % (-energy_changeres2 + energy) )
        # #res = [[i, j, c*W/abs(phi[i]-phi[j])] for i, j, c in edge]
        # if i % 10 == 0:
        #     print('=== after round %4d ===' % i)
        #     print('unchanged_energy = %f' %   energy_notchange)
        #     print('energy = %f' % energy)
        #     print('sqrt(energy) = %f' % np.sqrt(energy))

        #     c = max([flow[j][2]/edge[j][2] for j in range(len(edge))])
        # print([flow[j][2]/edge[j][2] for j in range(len(edge))])
    if len(min_cuts) > 1:
        flag = flag + "mulcut"
    return phi, flow, data1, data2, data3, data4, data5,flag

# In[ ]: j
# phi, flow , data, data2,data3, data4= altertating_minimization(n, edge)
# df = pd.DataFrame(data = data)
# df2 = pd.DataFrame(data = data2)
# df3 = pd.DataFrame(data = data3)
# df4 = pd.DataFrame(data = data4)
# df2.to_excel("energy.xlsx")
# df3.to_excel("wj.xlsx")

# df4.to_excel("nu.xlsx")
#
# w_1 = data
# x = [i for i in range(0,len(w_1))]
# w_1 = list(w_1)
#
#
# plt.plot(w_1)
# plt.show()