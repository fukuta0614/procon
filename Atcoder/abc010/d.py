def main():
    from itertools import product

    N, G, E = [int(_) for _ in input().split()]
    p = [int(_) for _ in input().split()]
    conn = [[int(_) for _ in input().split()] for i in range(E)]

    ans = float('inf')
    for x in product(range(2), repeat=E):
        L = [[] for _ in range(N)]
        num = 0
        for i, (a, b) in enumerate(conn):
            if x[i]:
                L[a].append(b)
                L[b].append(a)
            else:
                num += 1
        q = [0]
        visited = []
        while len(q) > 0:
            node = q.pop(0)
            for edge in L[node][:]:
                if edge in visited:
                    continue
                L[node].remove(edge)
                L[edge].remove(node)
                q.append(edge)
                visited.append(edge)
        num += len([1 for girl in p if girl in visited])
        ans = min(ans, num)

    print(ans)

def main2():
    from  collections import namedtuple, defaultdict


    class FlowNetwork(object):
        FlowEdge = namedtuple("FlowEdge", "src dist capacity")

        def __init__(self, n):
            self.adj = [[] for _ in range(n)]
            self.rev_edge = dict()
            self.visited = []
            self.flow = None

        def add_edge(self, src, dist, capacity):
            forward = self.FlowEdge(src, dist, capacity)
            backward = self.FlowEdge(dist, src, 0)
            self.rev_edge[forward] = backward
            self.rev_edge[backward] = forward
            self.adj[src].append(forward)
            self.adj[dist].append(backward)

        def dfs(self, node, t, flow):

            self.visited.append(node)

            if node == t:
                return flow

            for edge in self.adj[node]:
                dist = edge.dist
                rest = edge.capacity - self.flow[edge]
                if rest <= 0 or dist in self.visited:
                    continue
                d = self.dfs(dist, t, min(rest, flow))
                if d > 0:
                    self.flow[edge] += d
                    self.flow[self.rev_edge[edge]] -= d
                    return d

            return 0

        def ford_fulkerson(self, s, t):

            self.flow = defaultdict(int)

            max_flow = 0
            while True:
                self.visited = []
                d = self.dfs(s, t, float('inf'))
                if d == 0:
                    return max_flow
                else:
                    max_flow += d


    N, G, E = [int(_) for _ in input().split()]
    p = [int(_) for _ in input().split()]
    conn = [[int(_) for _ in input().split()] for i in range(E)]

    network = FlowNetwork(N + 1)

    for a, b in conn:
        network.add_edge(a, b, 1)
        network.add_edge(b, a, 1)

    for girl in p:
        network.add_edge(girl, N, 1)

    max_flow = network.ford_fulkerson(0, N)
    print(max_flow)

from  collections import namedtuple

N, G, E = [int(_) for _ in input().split()]
p = [int(_) for _ in input().split()]
conn = [[int(_) for _ in input().split()] for i in range(E)]

FlowEdge = namedtuple("FlowEdge", "src dist capacity")

graph = [[] for _ in range(N+1)]
for a, b in conn:
    graph[a].append(FlowEdge(a, b, 1))
    graph[b].append(FlowEdge(b, a, 1))
for girl in p:
    graph[girl].append(FlowEdge(girl, N, 1))

flow = [[0]*(N+1) for _ in range(N+1)]
max_flow = 0
s, t = 0, N

while True:
    visited = []
    prev = [-1] * (N + 1)
    q = [s]
    tmp_flow = float('inf')
    while len(q) > 0 and prev[t] < 0:
        node = q.pop()
        for edge in graph[node]:
            dist = edge.dist
            rest = edge.capacity - flow[node][dist]
            if rest <= 0 or prev[dist] >= 0:
                continue
            tmp_flow = min(rest, tmp_flow)
            prev[dist] = node
            q.append(dist)

    if prev[t] < 0 or tmp_flow <= 0:
        print(max_flow)
        break
    else:
        max_flow += tmp_flow
        node = t
        while node != s:
            flow[prev[node]][node] += tmp_flow
            flow[node][prev[node]] -= tmp_flow
            node = prev[node]
