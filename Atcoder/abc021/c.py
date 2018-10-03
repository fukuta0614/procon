from collections import defaultdict
import heapq

# N = 7
# a,b = 1,7
# M = 8
# xy = [[1, 2], [1, 3], [4, 2], [4, 3], [4, 5], [4, 6], [7, 5], [7, 6]]

N = int(input())
a, b = [int(_) for _ in input().split()]
M = int(input())
xy = [[int(_) for _ in input().split()] for i in range(M)]

road = defaultdict(list)
for i, j in xy:
    road[i].append(j)
    road[j].append(i)

dist = {i: float('inf') for i in range(1, N + 1)}
dist[a] = 0
q = [(0, a)]

while len(q) > 0:
    cost, src = heapq.heappop(q)

    for d in road[src]:
        tmp = cost + 1
        if tmp < dist[d]:
            dist[d] = tmp
            heapq.heappush(q, (tmp, d))

dp = defaultdict(int)
dp[a] = 1


def count_path(node):
    if node in dp:
        return dp[node]
    else:
        for d in road[node]:
            if dist[d] + 1 == dist[node]:
                dp[node] += count_path(d)
        return dp[node]


mod = 10 ** 9 + 7
print(count_path(b) % mod)
