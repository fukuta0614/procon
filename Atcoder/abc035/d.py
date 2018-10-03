import heapq

N, M, T = [int(_) for _ in input().split()]
A = [int(_) for _ in input().split()]

adj = [[] for i in range(N)]
rev = [[] for i in range(N)]
for i in range(M):
    a, b, c = [int(_) for _ in input().split()]
    adj[a-1].append((b-1, c))
    rev[b-1].append((a-1, c))

def dijkstra(adj):
    q = [(0, 0)]
    dist = [float('inf')] * N
    dist[0] = 0
    while len(q) > 0:
        cost, node = heapq.heappop(q)
        if cost < dist[node]:
            continue

        for edge, c in adj[node]:
            tmp = cost + c
            if tmp < dist[edge]:
                dist[edge] = tmp
                heapq.heappush(q, (tmp, edge))
    return dist

forward = dijkstra(adj)
backward = dijkstra(rev)

ans = 0
for i in range(N):
    t = T - forward[i] - backward[i]
    ans = max(ans, t * A[i])
print(ans)



