class UnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n + 1)]
        self.rank = [0] * (n + 1)
        self.num = [1] * (n + 1)
        self.sum = 0

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

            num = self.num[x] + self.num[y]
            self.sum += self.num[x] * self.num[y]
            self.num[x] = num
            self.num[y] = num

    # 同じ集合に属するか判定
    def same_check(self, x, y):
        return self.find(x) == self.find(y)


N, M = [int(_) for _ in input().split()]
T = [[int(_) for _ in input().split()] for i in range(M)]

uf = UnionFind(N)
C = (N - 1) * N // 2
ans = [C]
for a, b in reversed(T):
    uf.union(a, b)
    ans.append(C - uf.sum)

print(*reversed(ans[:-1]))