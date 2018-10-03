N = int(input())
T = [[int(_) - 1 for _ in input().split()] for i in range(N - 1)]

mod = 10**9 + 7

graph = [[] for i in range(N)]
for a, b in T:
    graph[a].append(b)
    graph[b].append(a)

f_memo = {}
g_memo = {}


def f(x, p):
    if x in f_memo:
        return f_memo[x]
    res = g(x, p)
    r = 1
    for y in graph[x]:
        if y == p:
            continue
        r *= g(y, x)
    res += r
    f_memo[x] = res
    return f_memo[x] % mod


def g(x, p):
    if x in g_memo:
        return g_memo[x]
    r = 1
    for y in graph[x]:
        if y == p:
            continue
        r *= f(y, x)
    res = r
    g_memo[x] = res
    return g_memo[x] % mod

print(f(0, -1))