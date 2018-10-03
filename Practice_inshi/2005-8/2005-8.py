
from collections import defaultdict

class Vertex(object):

    def __init__(self,x=None,y=None):
        if x is None and y is None:
            self.edge = []
        else:
            self.edge = [x,y]
        self.adjacent_area = []

    def add_edge(self,vertex):
        self.edge.append(vertex)

    def life(self):
        return 3 - len(self.edge)

class Area(object):

    def __init__(self):
        self.single_vertexes = []
        self.connections = []

    def add_single(self,index):
        self.single_vertexes.append(index)

class Sprouts(object):

    def __init__(self,n):
        self.vertexes = {}
        self.Areas = defaultdict(list)
        for i in range(1,n+1):
            self.vertexes[i] = Vertex()
            self.Areas[1].append(i)

        self.vertex_num = 3
        self.connections = [1,2,3]

    def write(self,adjacent_vertexes,adjacent_areas,):
        pass

    def move(self,x,y,round=None):
        if round is None:
            self.vertex_num += 1
            self.vertexes[self.vertex_num] = Vertex()
            self.vertexes[x].add_edge(self.vertex_num)
            self.vertexes[y].add_edge(self.vertex_num)

            # vertexes = list(range(1,self.vertex_num+1))
            # connections = []
            # i = 0
            # while len(vertexes) > 0:
            #     connections.append({vertexes[0]})
            #     while True:
            #         temp = len(connections[i])
            #         for v in list(connections[i]):
            #             connections[i].update(self.vertexes[v])
            #         if len(connections[i]) == temp:
            #             break
            #     for v in list(connections[i]):
            #         vertexes.remove(v)
            #     i += 1

    def play(self):
        pass

def kadai3():
    s = Sprouts(3)

if __name__ == '__main__':
    kadai3()