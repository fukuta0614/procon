from itertools import permutations, combinations
import heapq

N, M = [int(_) for _ in input().split()]
uvl = [[int(_) for _ in input().split()] for i in range(M)]

L = [[float('inf')] * N for _ in range(N)]
for i, j, l in uvl:
    L[i - 1][j - 1] = L[j - 1][i - 1] = l

dist = [float('inf')] * N
dist[0] = 0
group = [-1] * N
que = [[0, 0]]
while len(que) > 0:
    [c, v] = heapq.heappop(que)
    if dist[v] != c:
        continue
    for i in range(N):
        if dist[i] > dist[v] + L[v][i]:
            dist[i] = dist[v] + L[v][i]
            if v == 0:
                group[i] = i
            else:
                group[i] = group[v]
            heapq.heappush(que, [dist[i], i])

ans = float('inf')
for i in range(1, N):
    if group[i] != i:
        ans = min(ans, dist[i] + L[0][i])
    for j in range(i + 1, N):
        if group[j] != group[i]:
            ans = min(ans, dist[i] + dist[j] + L[i][j])
if ans == float('inf'):
    ans = -1
print(ans)


def low_speed():
    dist = [[float('inf')] * N for _ in range(N)]
    for i, j, l in uvl:
        dist[i - 1][j - 1] = l
        dist[j - 1][i - 1] = l

    for k in range(1, N):
        for i in range(1, N):
            for j in range(1, N):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

    candidate = []
    for v in range(N):
        if dist[0][v] != float('inf'):
            candidate.append(v)

    ans = float('inf')
    for i, j in combinations(candidate, 2):
        if dist[i][j] != float('inf'):
            ans = min(ans, dist[0][i] + dist[i][j] + dist[j][0])

    if ans == float('inf'):
        print(-1)
    else:
        print(ans)
