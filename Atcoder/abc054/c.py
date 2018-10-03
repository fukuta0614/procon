
N, M = [int(_) for _ in input().split()]
T = [[int(_) - 1 for _ in input().split()] for i in range(M)]

graph = [[] for i in range(N)]
for a, b in T:
    graph[a].append(b)
    graph[b].append(a)


def dfs(node, prev, visited):
    visited.append(node)
    if len(visited) == N:
        return 1

    res = 0
    for edge in graph[node]:
        if edge == prev:
            continue
        if edge in visited:
            continue

        res += dfs(edge, prev, visited[:])

    return res

print(dfs(0, -1, []))