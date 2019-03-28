import numpy as np

N = int(input())
T = [[int(_) for _ in input().split()] for i in range(N)]


class UnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n + 1)]
        self.rank = [0] * (n + 1)

    # 検索
    def find(self, x):
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]

    # 併合
    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x != y:
            if self.rank[x] < self.rank[y]:
                self.par[x] = y
            else:
                self.par[y] = x
                if self.rank[x] == self.rank[y]:
                    self.rank[x] += 1

    # 同じ集合に属するか判定
    def same_check(self, x, y):
        return self.find(x) == self.find(y)


E = []
indices_x = np.argsort([x for x, y in T])
indices_y = np.argsort([y for x, y in T])

for i in range(N - 1):
    a, _ = T[indices_x[i]]
    c, _ = T[indices_x[i + 1]]
    E.append((indices_x[i], indices_x[i + 1], abs(a - c)))

    _, b = T[indices_y[i]]
    _, d = T[indices_y[i + 1]]
    E.append((indices_y[i], indices_y[i + 1], abs(b - d)))

uf = UnionFind(N)
ans = 0
for i, j, cost in sorted(E, key=lambda x: x[2]):
    if uf.same_check(i, j):
        continue

    uf.union(i, j)
    ans += cost

print(ans)
