from graph_tool.all import *
import numpy as np
from numpy.core.numeric import ones
from numpy.random import *  # for random sampling
from altermini import *
import os


def random_graph(max_vertex, max_capacity):
    seed(42)
    g = Graph()
    e_cap = g.new_edge_property("int")
    e_dict = {}
    for i in range(0, max_vertex):
        g.add_vertex()
    for i in range(0, max_vertex):
        for j in range(i + 1, max_vertex):
            if (i == 0 and j == max_vertex - 1) or (i, j) in e_dict:
                continue
            if (randint(1, 100) / 100) > 0.5:
                srs = g.vertex(i)
                tgt = g.vertex(j)
                e = g.add_edge(srs, tgt)
                e_cap[e] = randint(1, max_capacity)
                e_dict[(i, j)] = 1
                e_dict[(j, i)] = 1
    return g, e_cap


def random_graph_mulcut(max_vertex, max_capacity):
    seed(42)
    g = Graph()
    e_cap = g.new_edge_property("int")
    e_dict = {}
    for i in range(0, max_vertex):
        g.add_vertex()
    for i in range(0, max_vertex):
        for j in range(i + 1, max_vertex):
            if (i == 0 and j == (max_vertex - 1)) or (i, j) in e_dict:
                continue
            if (randint(1, 100) / 100) > 0.5:
                srs = g.vertex(i)
                tgt = g.vertex(j)
                e = g.add_edge(srs, tgt)
                if i == 0 or j == (max_vertex - 1):
                    e_cap[e] = randint(1, max_capacity * 2)
                else:
                    e_cap[e] = randint(1, max_capacity / 2)
                e_dict[(i, j)] = 1
                e_dict[(j, i)] = 1
    return g, e_cap


def debug_graph(file):
    edge = pd.read_excel(file, usecols=[1, 2, 3])
    edge = edge[:-1]
    edge = edge.values.tolist()
    n = 1
    for i in range(0, len(edge)):
        n = max(edge[i][0], n)
        n = max(edge[i][1], n)
    n += 1
    g, e_cap = nedge_g(n, edge)
    return g, e_cap, edge, n


def e2graph(edge):
    n = 1
    for i in range(0, len(edge)):
        n = max(edge[i][0], n)
        n = max(edge[i][1], n)
    n += 1
    n = int(n)
    g, e_cap = nedge_g(n, edge)
    n, edge = g_nedge(g, e_cap)
    return g, e_cap, edge, n


"""
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
"""


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
    e_cap = g.new_edge_property("float")
    for i in range(0, n):
        g.add_vertex()
    for e in edge:
        v1 = e[0]
        v2 = e[1]
        v1 = g.vertex(v1)
        v2 = g.vertex(v2)
        t = g.add_edge(v1, v2)
        e_cap[t] = e[2]
    # g.edge_properties["cap"] = e_cap
    return g, e_cap


def g_nedge(g, e_cap):
    edge_list = []
    # g.edge_properties["cap"] = e_cap
    for e in g.edges():
        single_edge = [int(e.source()), int(e.target()), e_cap[e]]
        edge_list.append(single_edge)
    return g.num_vertices(), edge_list

def g_nedge2(g, e_cap):
    edge_list = []
    # g.edge_properties["cap"] = e_cap
    index = 0
    for e in g.edges():
        single_edge = [int(e.source()), int(e.target()), e_cap[index]]
        edge_list.append(single_edge)
        index += 1
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
    dir = "/data5/"
    if not os.path.exists(dir[1:-1]):
        os.mkdir(dir[1:-1])
    filepath = os.getcwd() + dir + "output_" + str(ind) + ".png"
    flag = np.ones(g.num_vertices() +1)
    graph_draw(
        g,
        pos=pos,
        vertex_size=20,
        vertex_fill_color=flag,
        vertex_text=g.vertex_index,
        output=filepath,
    )


def find_mincut(phi, g):
    min_cuts = []
    pre = np.ones(len(phi))
    for j in range(1, 10):
        ind = j / 10
        flag = np.ones(len(phi))
        index = 0
        min_cut = []
        for i in range(0, len(phi)):
            if phi[i] < ind:
                flag[i] = 0
            else:
                flag[i] = 1
        if (pre == flag).all():
            continue
        for e in g.edges():
            v1 = int(e.source())
            v2 = int(e.target())
            if flag[v1] != flag[v2]:
                min_cut.append(index)
            index += 1
        min_cuts.append(min_cut)
        pre = flag
    return min_cuts, flag


def rd_edges():
    path = os.getcwd() + "/graph_dataset/"
    files = os.listdir(path)
    edges = []
    is_excel = 0
    for file in files:
        if file.split(".")[-1] == "xlsx":
            is_excel = 1
        edge = []
        if not os.path.isdir(file):
            f = open(path + "/" + file)
            if is_excel:
                edge = pd.read_excel(path + file, usecols=[1, 2, 3])
                edge = edge[:-1]
                edge = edge.values.tolist()
            else:
                for line in f:
                    try:
                        e_i = [float(item) for item in line[:-1].split(" ")]
                    except:
                        pass
                    else:
                        e_i[0] = int(e_i[0] )
                        e_i[1] = int(e_i[1] )
                        e_i.append(1)
                        edge.append(e_i)
            edges.append(edge)
    return edges


def to_excel(edge, data1, data2, data3, data4, is_mul, *args):
    f = is_mul
    try:
      f += args[0]
    except:
      pass
    cap = pd.DataFrame(data=edge)
    df1 = pd.DataFrame(data=data1)
    df2 = pd.DataFrame(data=data2)
    df3 = pd.DataFrame(data=data3)
    df4 = pd.DataFrame(data=data4)
    dir = "/data5/"
    if not os.path.exists(dir[1:-1]):
        os.mkdir(dir[1:-1])
    filepath = os.getcwd() + dir
    cap.to_excel(filepath + "cap_" + f + ".xlsx")
    df1.to_excel(filepath + "phi__" + f + ".xlsx")
    df2.to_excel(filepath + "energy__" + f + ".xlsx")
    df3.to_excel(filepath + "weights__" + f + ".xlsx")
    df4 = df4.T
    df4.to_excel(filepath + "nu__" + f + ".xlsx")

def exer_graph():
        label = "test_graph_8"
        n, edge = globals()[label]()
        g, e_cap = nedge_g(n, edge)
        n, edge = g_nedge(g, e_cap)
        phi, flow, data1, data2, data3, data4, f = altertating_minimization(
            n,
            edge,
        )
        min_cuts, _ = find_mincut(phi, g)
        phi, flow, data1, data2, data3, data4, f = altertating_minimization(
            n, edge, min_cuts, int(data2[-1])
        )
        edge.append(min_cuts)
        draw(g, label)
        to_excel(edge, data1, data2, data3, data4, f, label)
    
    


def test_origp():
    for i in range(1, 7):
        label = "test_graph_" + str(i)
        n, edge = globals()[label]()
        g, e_cap = nedge_g(n, edge)
        n, edge = g_nedge(g, e_cap)
        phi, flow, data1, data2, data3, data4, f = altertating_minimization(
            n,
            edge,
        )
        min_cuts, _ = find_mincut(phi, g)
        phi, flow, data1, data2, data3, data4, f = altertating_minimization(
            n, edge, min_cuts, int(data2[-1])
        )
        edge.append(min_cuts)
        draw(g, label)
        to_excel(edge, data1, data2, data3, data4, f, label)


def test_rdgp():
    for i in range(4, 100):
        label = str(i)
        g, e_cap = random_graph_mulcut(i, 40)
        n, edge = g_nedge(g, e_cap)
        phi, flow, data1, data2, data3, data4, is_mul= altertating_minimization(
            n,
            edge,
        )
        min_cuts, _ = find_mincut(phi, g)

        phi, flow, data1, data2, data3, data4, is_mul= altertating_minimization(
            n, edge, min_cuts, int(data2[-1])
        )
        edge.append(min_cuts)
        draw(g, label)
        to_excel(edge, data1, data2, data3, data4, is_mul, label)

def debug_gp():
    label = "debug"
    filepath = os.getcwd() + "/data1/capacity__y54.xlsx"
    g, e_cap, edge, n = debug_graph(filepath)
    phi, flow, data1, data2, data3, data4, is_mul= altertating_minimization(
        n,
        edge,
    )
    min_cuts, _ = find_mincut(phi, g)
    """
    cut_value = 0
    for i in min_cut:
        cut_value += edge[i][2]
    """
    phi, flow, data1, data2, data3, data4, is_mul= altertating_minimization(
        n, edge, min_cuts, int(data2[-1])
    )
    edge.append(min_cuts)
    draw(g, label)
    to_excel(edge, data1, data2, data3, data4, is_mul, label)


def test_dbgp():
    edges = rd_edges()
    for e_ in edges:
        g, e_cap, edge, n = e2graph(e_)
        phi, flow, data1, data2, data3, data4, is_mul= altertating_minimization(n, edge)
        min_cuts, _ = find_mincut(phi, g)
        cut_value = 0
        
        for i in min_cuts[0]:
          cut_value += edge[i][2]
        draw(g)
        phi, flow, data1, data2, data3, data4, is_mul= altertating_minimization(
            n, edge, min_cuts, int(data2[-1])
        )
        edge.append(min_cuts)
        to_excel(edge, data1, data2, data3, data4, is_mul)
  
def test_ggp():
     g =  collection.data["karate"]
     e_cap = np.ones(g.num_edges())
     n, edge = g_nedge2(g, e_cap)
     phi, flow, data1, data2, data3, data4, is_mul = altertating_minimization(n, edge)
     draw(g)
     min_cuts, _ = find_mincut(phi, g)
     phi, flow, data1, data2, data3, data4, is_mul = altertating_minimization(
            n, edge, min_cuts, int(data2[-1])
        )
     edge.append(min_cuts)
     to_excel(edge, data1, data2, data3, data4, is_mul)


if __name__ == "__main__":
    # main()
    # main1()
    # main2()
    # main3()
    # main4()
    # test_rdgp()
    # exer_graph()
    test_dbgp()
