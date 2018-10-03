def main1():
    n = int(input())
    xy = [[int(_) - 1 for _ in input().split()] for i in range(n - 1)]

    Q = int(input())
    ab = [[int(_) - 1 for _ in input().split()] for i in range(Q)]

    if Q <= 10:
        for a, b in ab:
            adj = [[] for i in range(n)]
            for x, y in xy:
                adj[x].append(y)
                adj[y].append(x)

            q = [(0, a)]
            res = 0
            visited = [False] * n
            while len(q) > 0:
                cost, node = q.pop()
                visited[node] = True
                for edge in adj[node]:
                    if edge == b:
                        res = cost + 1
                        break
                    if not visited[edge]:
                        q.append((cost + 1, edge))

                if res > 0:
                    break
            print(res + 1)
    else:
        print(0)



n = int(input())
xy = [[int(_) - 1 for _ in input().split()] for i in range(n - 1)]

Q = int(input())
ab = [[int(_) - 1 for _ in input().split()] for i in range(Q)]

adj = [[] for i in range(n)]
for x, y in xy:
    adj[x].append(y)
    adj[y].append(x)

log_max_depth = 20
parent = [[-1] * n for i in range(log_max_depth)]
depth = [-1] * n


# init
def dfs(u, p, d):
    parent[0][u] = p
    depth[u] = d
    for v in adj[u]:
        if v == p:
            continue
        dfs(v, u, d + 1)

dfs(0, -1, 0)

for k in range(log_max_depth-1):
    for v in range(n):
        if parent[k][v] < 0:
            parent[k + 1][v] = -1
        else:
            parent[k + 1][v] = parent[k][parent[k][v]]

log_max_depth = len(format(max(depth), 'b'))

def lca(u, v):
    if depth[u] > depth[v]:
        u, v = v, u

    diff = depth[v] - depth[u]
    for k in range(log_max_depth):
        if diff >> k & 1:
            v = parent[k][v]

    if u == v:
        return u

    for k in list(range(log_max_depth))[::-1]:
        if parent[k][u] != parent[k][v]:
            u = parent[k][u]
            v = parent[k][v]

    return parent[k][u]


for a, b in ab:
    p = lca(a, b)
    print(depth[a] + depth[b] - 2 * depth[p] + 1)
