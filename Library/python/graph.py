import heapq

V, E = [int(_) for _ in input().split()]
uvl = [[int(_) for _ in input().split()] for i in range(E)]

adj = [[0] * V for _ in range(V)]
for i, j, l in uvl:
    adj[i][j] = l
    adj[j][i] = l

dist = [float('inf')] * V
prev = [-1] * V
q = [(0, 0, -1)]

T = []
while len(T) < V:
    cost, u, _ = heapq.heappop(q)
    T.append(u)

    for v in range(V):
        if adj[u][v] > 0 and not v in T:
            tmp = adj[u][v]
            if tmp < dist[v]:
                dist[v] = tmp
                prev[v] = u
                heapq.heappush(q, (tmp, v, u))
ans = 0
for v in range(V):
    if prev[v] != -1:
        ans += adj[v][prev[v]]

print(ans)