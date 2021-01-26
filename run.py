from sys import flags
from graph_tool.all import *
import numpy as np
from numpy.random import *  # for random sampling
from altermini import *
import os


def random_graph(max_vertex, max_capacity):
    seed(42)
    g = Graph()
    e_cap = g.new_edge_property("int")
    elist = {}
    for i in range(0, max_vertex):
        g.add_vertex()
    for i in range(0, max_vertex):
        for j in range(i + 1, max_vertex):
            if (i == 0 and j == max_vertex - 1) or (i, j) in elist:
                continue
            if (randint(1, 100) / 100)> 0.5:
                srs = g.vertex(i)
                tgt = g.vertex(j)
                e = g.add_edge(srs, tgt)
                e_cap[e] = randint(1, max_capacity)
                elist[(i, j)] = 1
                elist[(j, i)] = 1
    return g, e_cap


def read_graph(fp):
    edge = pd.read_excel(fp, usecols=[1, 2, 3])
    edge = edge[:-1]
    edge[2] = edge[2].astype("int")
    edge = edge.values.tolist()
    n = 1
    for i in range(0, len(edge)):
        n = max(edge[i][0], n)
        n = max(edge[i][1], n)
    g, e_cap = nedge_g(n + 1, edge)
    return g, e_cap, edge, n + 1


def random_graph_1(max_vertex, max_capacity):
    seed(42)
    g = Graph()
    N = randint(0, max_vertex)
    e_cap = g.new_edge_property("int")
    source = g.add_vertex()
    v = g.add_vertex()
    vlist = [source, v]
    for i in range(1, N):
        # create our new vertex
        v = g.add_vertex()
        # we need to sample a new vertex to be the target, based on its in-degree +
        # 1. For that, we simply randomly sample it from vlist.
        j = randint(1, len(vlist))
        if j != i:
            target = vlist[j]
            # add edge
            e = g.add_edge(v, target)
            e_cap[e] = randint(1, max_capacity)
            # put v and target in the list
            vlist.append(target)
            vlist.append(v)
    tgt = g.add_vertex()
    vlist.append(tgt)
    for i in range(0, g.num_vertices() - 1):
        v = g.vertex(i)
        e = g.add_edge(v, tgt)
        e_cap[e] = randint(1, max_capacity)
        # put v and target in the list
    return g, e_cap


# g = Graph()
# v1 = g.add_vertex()
# v2 = g.add_vertex()
# v3 = g.add_vertex()
# v4 = g.add_vertex()
# e_ind = g.new_edge_property("int")
# e = g.add_edge(v1, v2)
# es.append(e)
# e_ind[e]  = 1
# e = g.add_edge(v2, v3)
# e_ind[e]  = 2
# es.append(e)
# e = g.add_edge(v1, v3)
# e_ind[e]  = 3
# es.append(e)
def nedge_g(n, edge):
    g = Graph()
    e_cap = g.new_edge_property("int")
    for i in range(0, n):
        g.add_vertex()
    for e in edge:
        v1 = e[0]
        v2 = e[1]
        v1 = g.vertex(v1)
        v2 = g.vertex(v2)
        t = g.add_edge(v1, v2)
        e_cap[t] = e[2]
    g.edge_properties["cap"] = e_cap
    return g, e_cap


def g_nedge(g, e_cap):
    edge_list = []
    g.edge_properties["cap"] = e_cap
    for e in g.edges():
        single_edge = [int(e.source()), int(e.target()), e_cap[e]]
        edge_list.append(single_edge)
    return g.num_vertices(), edge_list


# v_index = g.new_vertex_property("int")
# v_index.a = np.array(range( 0, g.num_vertices()))
def draw(g, ind=-1):
    v_index1 = g.new_vertex_property("int")
    v_index1.a = np.ones(g.num_vertices())
    g.set_directed(False)
    # g.vertex_properties['index'] = v_index
    min_x = 10000
    max_x = -min_x
    avg_y = 0
    pos = sfdp_layout(g)
    for i in pos:
        min_x = min(i[0], min_x)
        max_x = max(i[0], max_x)
        avg_y += i[1]
    avg_y = avg_y / g.num_vertices()
    pos[0] = [min_x - 1, avg_y]
    pos[g.num_vertices() - 1] = [max_x + 1, avg_y]
    filepath = os.getcwd() + "/data/output_" + str(ind) + ".png"
    flag = np.ones(g.num_vertices())
    graph_draw(
        g,
        pos=pos,
        vertex_size=20,
        vertex_fill_color=flag,
        vertex_text=g.vertex_index,
        output=filepath,
    )


def find_mincut(phi, g):
    flag = np.ones(len(phi))
    index = 0
    min_cut = []
    for i in range(0, len(phi)):
        if phi[i] < 0.5:
            flag[i] = 0
        else:
            flag[i] = 1
    for e in g.edges():
        v1 = int(e.source())
        v2 = int(e.target())
        if flag[v1] != flag[v2]:
            min_cut.append(index)
        index += 1
    return min_cut, flag


def to_excel(edge, data1, data2, data3, data4, f, *args):
    cap = pd.DataFrame(data=edge)
    df1 = pd.DataFrame(data=data1)
    df2 = pd.DataFrame(data=data2)
    df3 = pd.DataFrame(data=data3)
    df4 = pd.DataFrame(data=data4)
    f += args[0]
    filepath = os.getcwd() + "/data/"
    cap.to_excel(filepath + "capacity__" + f + ".xlsx")
    df1.to_excel(filepath + "phi__" + f + ".xlsx")
    df2.to_excel(filepath + "energy__" + f + ".xlsx")
    df3.to_excel(filepath + "weights__" + f + ".xlsx")
    df4.to_excel(filepath + "nu__" + f + ".xlsx")


def main():
    for i in range(1, 7):
        label = "test_graph_" + str(i)
        n, edge = globals()[label]()
        g, e_cap = nedge_g(n, edge)
        n, edge = g_nedge(g, e_cap)
        phi, flow, data1, data2, data3, data4, f = altertating_minimization(
            n,
            edge,
        )
        min_cut, flag = find_mincut(phi, g)
        phi, flow, data1, data2, data3, data4, f = altertating_minimization(
            n, edge, min_cut, int(data2[-1])
        )
        edge.append(min_cut)
        draw(g,label)
        to_excel(edge, data1, data2, data3, data4, f, label)




def main1():
    for i in range(4, 100):
        label = str(i)
        g, e_cap = random_graph(i, 30)
        n, edge = g_nedge(g, e_cap)
        phi, flow, data1, data2, data3, data4, f = altertating_minimization(
            n,
            edge,
        )

        min_cut, flag = find_mincut(phi, g)

        phi, flow, data1, data2, data3, data4, f = altertating_minimization(
            n, edge, min_cut, int(data2[-1])
        )
        edge.append(min_cut)
        draw(g, label)
        to_excel(edge, data1, data2, data3, data4, f, label)

def main2():
    label = "debug"
    filepath = os.getcwd() + "/data/capacity__ntest_graph_2.xlsx"
    g, e_cap, edge, n = read_graph(filepath)
    phi, flow, data1, data2, data3, data4, f = altertating_minimization(
        n,
        edge,
    )
    min_cut, flag = find_mincut(phi, g)
    phi, flow, data1, data2, data3, data4, f = altertating_minimization(
        n, edge, min_cut, int(data2[-1])
    )
    edge.append(min_cut)
    draw(g, label)
    to_excel(edge, data1, data2, data3, data4, f,label) 

if __name__ == "__main__" :
    main2()
    main()
