from sys import setrecursionlimit, stdin, stdout, stderr
from time import time
import gc
from os import _exit

gc.disable()
setrecursionlimit(210000)

_data = map(int, stdin.read().split())

# t = time()
n = next(_data)
g = [[] for i in range(n)]
for i in range(n - 1):
    u, v = next(_data) - 1, next(_data) - 1
    g[u].append(v)
    g[v].append(u)
# print('init graph:', time() - t, file=stderr)

# t = time()
q = next(_data)
ans = [0] * q
h = [[] for i in range(n)]
for i in range(q):
    u, v = next(_data) - 1, next(_data) - 1
    h[u].append((v, i))
    h[v].append((u, i))

used = [False] * n
depth = [0] * n
par = list(range(n))


# print('init query:', time() - t, file=stderr)

def find(x, par=par):
    if x == par[x]:
        return x
    par[x] = find(par[x])
    return par[x]


def lca(v, p, depth=depth, find=find, used=used, ans=ans, par=par, g=g, h=h):
    print(v, depth, par)
    d = depth[v]
    for u in g[v]:
        if u != p:
            depth[u] = d + 1
            lca(u, v)
            par[u] = v
    used[v] = True
    for u, i in h[v]:
        if used[u]:
            print(u, v, par)
            l = find(u)
            print(u, v, l, depth, par)
            ans[i] = d + depth[u] - (depth[l] << 1) + 1


# t = time()
lca(0, -1)
# print('lca: ', time() - t, file=stderr)

# t = time()
print('\n'.join(map(str, ans)))
stdout.flush()
# print('output: ', time() - t, file=stderr)
_exit(0)