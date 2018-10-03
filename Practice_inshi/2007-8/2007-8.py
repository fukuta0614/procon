from collections import defaultdict
from itertools import combinations
import pprint
pp = pprint.PrettyPrinter(indent=4)


class Graph(object):

    def __init__(self,edges):
        self.edges = []
        self.edge_dict = defaultdict(list)
        for edge in edges:
            self.edge_dict[edge[0]].append(edge[1])
            self.edge_dict[edge[1]].append(edge[0])
            self.edges.append(set(edge))
        self.cluster_dict = defaultdict(int)


    def calc_distance_ave(self):
        sum_of_distance = 0
        for x,y in combinations(range(1,101),2):
            sum_of_distance += self.calc_distance(x,y)
        print(sum_of_distance/4950)

    def calc_distance_max(self):
        max_of_distance = 0
        for x,y in combinations(range(1,101),2):
            max_of_distance = max(max_of_distance,self.calc_distance(x,y))
        return max_of_distance

    def calc_distance(self,x,y):
        distance = 1
        reachable_set = defaultdict(set)
        reachable_set[0] = {x}
        while True:
            for vertex in list(reachable_set[distance-1]):
                if y in self.edge_dict[vertex]:
                    # print(reachable_set)
                    return distance
                reachable_set[distance].update(self.edge_dict[vertex])
            distance += 1

    def calc_cluster(self):

        for vertex in range(1,101):
            W = self.edge_dict[vertex]
            if len(W) < 2:
                self.cluster_dict[vertex] = 0
            else:
                C = list(combinations(W,2))
                for c in C:
                    if set(c) in self.edges:
                        self.cluster_dict[vertex] += 1
                self.cluster_dict[vertex] /= len(C)

        # for k in range(1,11):
        #     print(k,self.cluster_dict[k])
        print('average of cluster keisuu',sum([ value for k, value in self.cluster_dict.items()])/100)

    def calc_concatenate_ex(self):
        concatenate_dict = {}
        not_belong_vertex_list = list(range(1,101))
        graph_id = 0
        temp = 0
        concatenate_dict[graph_id] = {not_belong_vertex_list[0]}
        while True:
            for vertex in not_belong_vertex_list:
                if vertex in concatenate_dict[graph_id]:
                    concatenate_dict[graph_id].update(self.edge_dict[vertex])

            if len(concatenate_dict[graph_id]) == temp:
                for vertex in concatenate_dict[graph_id]:
                    not_belong_vertex_list.remove(vertex)
                graph_id += 1
                if len(not_belong_vertex_list) > 0:
                    return False
                else:
                    self.calc_cluster()
                    return True
            temp = len(concatenate_dict[graph_id])

        print(sorted([ len(vertexes) for k,vertexes in concatenate_dict.items()],reverse=True))

    def calc_concatenate(self):
        concatenate_dict = {}
        not_belong_vertex_list = list(range(1,101))
        graph_id = 0
        temp = 0
        concatenate_dict[graph_id] = {not_belong_vertex_list[0]}
        while True:
            for vertex in not_belong_vertex_list:
                if vertex in concatenate_dict[graph_id]:
                    concatenate_dict[graph_id].update(self.edge_dict[vertex])

            if len(concatenate_dict[graph_id]) == temp:
                for vertex in concatenate_dict[graph_id]:
                    not_belong_vertex_list.remove(vertex)
                graph_id += 1
                if len(not_belong_vertex_list)==0:
                    break
                concatenate_dict[graph_id] = {not_belong_vertex_list[0]}

            temp = len(concatenate_dict[graph_id])

        print(sorted([ len(vertexes) for k,vertexes in concatenate_dict.items()],reverse=True))

def kadai2():
    with open('edges.txt') as f:
        edges = f.read().split('\n')[:-1]

    for i in range(len(edges)):
        edges[i] = list((map(lambda x:int(x),edges[i].split(' '))))

    print("2-1")
    g = Graph(edges[:181])
    g.calc_concatenate()
    print('2-2')
    print('2-3')
    g.calc_cluster()
    print('2-4')
    for i in range(1,len(edges)+1):
        g = Graph(edges[:i])
        if g.calc_concatenate_ex():
            print(i,'renketu!')
            break
    print('2-5')
    g = Graph(edges[:302])
    g.calc_cluster()


def kadai3():
    with open('edges.txt') as f:
        edges = f.read().split('\n')[:-1]

    for i in range(len(edges)):
        edges[i] = list((map(lambda x:int(x),edges[i].split(' '))))

    g = Graph(edges[:202])
    print(g.calc_distance(27,63))
    g.calc_distance_ave()

    g = Graph(edges[:302])
    print(g.calc_distance(27,63))
    g.calc_distance_ave()

    for i in range(202,len(edges)+1):
        g = Graph(edges[:i])
        print(i,g.calc_distance_max())

if __name__ == '__main__':

    kadai3()