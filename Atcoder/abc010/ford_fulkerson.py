#!/usr/bin/env python3

import array
import collections
import sys

#: The value representing "infinity."
INF = 10 ** 8

#: The maxium number of recursion.
REC_LIMIT = 10000

#: Named tuple representing a edge in the flow network in question.
FlowEdge = collections.namedtuple("FlowEdge", "source sink capacity")


class FlowNetwork(object):
    """Class representing a flow network.

    :param int num_vertices: The number of vertices in the network.
    """

    def __init__(self, num_vertices):
        self.adj_edges = [set() for _ in range(num_vertices)]
        self.flow = None
        self.rev_edge = dict()
        self.used = None

    def get_edges_from(self, vertex):
        """Returns the set of edges adjacent to the vertex.

        :param int vertex: The index of vertex.
        :returns: The set of edges adjacent to the vertex.
        :rtype: set
        """

        return self.adj_edges[vertex]

    def add_edge(self, source, sink, capacity):
        """Add an edge u -> v to the flow network.

        :param int source: The vertex u.
        :param int sink: The vertex v.
        :param int capacity: The capacity of the edge.
        """

        assert source != sink
        forward_edge = FlowEdge(source, sink, capacity)
        backward_edge = FlowEdge(sink, source, 0)
        self.rev_edge[forward_edge] = backward_edge
        self.rev_edge[backward_edge] = forward_edge
        self.adj_edges[source].add(forward_edge)
        self.adj_edges[sink].add(backward_edge)

    def dfs(self, source, sink, flow):
        """Finding augmenting paths using depth-first search.

        This method is not supposed to be used directly.
        Instead, use :meth:`FlowNetwork.ford_fulkerson`.
        """

        if source == sink:
            return flow
        self.used[source] = True
        for edge in self.get_edges_from(source):
            rest = edge.capacity - self.flow[edge]
            if self.used[edge.sink] or rest <= 0:
                continue
            d = self.dfs(edge.sink, sink, min(flow, rest))
            if d > 0:
                self.flow[edge] += d
                self.flow[self.rev_edge[edge]] -= d
                return d
        return 0

    def ford_fulkerson(self, source, sink):
        """Computing maximum flow using the Ford-Fulkerson algorithm.

        :param int source: The source.
        :param int sink: The sink.
        :return: Maximum flow.
        """

        self.flow = collections.defaultdict(int)
        max_flow = 0
        while True:
            self.used = collections.defaultdict(bool)
            df = self.dfs(source, sink, INF)
            if df == 0:
                return max_flow
            else:
                max_flow += df


def main():
    sys.setrecursionlimit(REC_LIMIT)
    n, g, e = map(int, input().split())
    marked_girls = array.array("L", map(int, input().split()))
    network = FlowNetwork(n + 1)
    for _ in range(e):
        a, b = map(int, input().split())
        network.add_edge(a, b, 1)
        network.add_edge(b, a, 1)
    for g in marked_girls:
        network.add_edge(g, n, 1)
    mf = network.ford_fulkerson(0, n)
    print(mf)


if __name__ == '__main__':
    main()