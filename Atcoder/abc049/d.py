N, K, L = [int(_) for _ in input().split()]
V1 = [[int(_) - 1 for _ in input().split()] for i in range(K)]
V2 = [[int(_) - 1 for _ in input().split()] for i in range(L)]


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


uf1 = UnionFind(N)
for p, q in V1:
    uf1.union(p, q)

uf2 = UnionFind(N)
for r, s in V2:
    uf2.union(r, s)

from collections import defaultdict
d = defaultdict(int)

for i in range(N):
    d[(uf1.find(i), uf2.find(i))] += 1

for i in range(N):
    print(d[(uf1.find(i), uf2.find(i))], end=' ')
print()
