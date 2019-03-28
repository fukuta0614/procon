import math

L = int(input())
n = int(math.log2(L))
N = n + 1

edges = []
for i in range(1, N):
    edges.append((i, i + 1, 0))
    edges.append((i, i + 1, 2 ** (n - i)))

res = L - 2 ** n
bits = format(res, '0' + str(n) + 'b')
weight = 2 ** n
for i, bit in enumerate(bits):
    if int(bit):
        edges.append((1, i + 2, weight))
        weight += 2 ** (n - i - 1)

print(N, len(edges))
for row in edges:
    print(*row)

#
# def solve(x):
#     n = int(math.log2(x))
#     N = n + 1
#
#     edges = []
#     for i in range(1, N):
#         edges.append((i, i + 1, 0))
#         edges.append((i, i + 1, 2 ** (n - i)))
#
#     res = x - 2 ** n
#     bits = format(res, '0' + str(n) + 'b')
#     weight = 2 ** n
#     for i, bit in enumerate(bits):
#         if int(bit):
#             edges.append((1, i + 2, weight))
#             weight += 2 ** (n - i - 1)
#
#     return N, edges
#
#
# def check(x):
#     from collections import defaultdict
#     N, edges = solve(x)
#
#     graph = defaultdict(list)
#     for p, q, w in edges:
#         graph[p].append((q, w))
#
#     cost = []
#
#     def dfs(v, l):
#         if v == N:
#             cost.append(l)
#             return l
#         for dst, w in graph[v]:
#             dfs(dst, l + w)
#
#     dfs(1, 0)
#
#     def f(a):
#         return a * (a - 1) / 2
#
#     res = len(cost) == x and sum(cost) == f(x)
#     if not res:
#         print(x, N)
#         print(edges)
#         print(cost)
#     return res
#
#
# for x in range(2, 100001, 10):
#     print(x)
#     if not check(x):
#         break
