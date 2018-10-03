N, M = [int(_) for _ in input().split()]
aby = [[int(_)-1 for _ in input().split()] for i in range(M)]
Q = int(input())
vw = [[int(_)-1 for _ in input().split()] for i in range(Q)]


class UnionFind:
    def __init__(self, size):
        self.parent = [-1 for _ in range(size)]
        self.count = [1 for _ in range(size)]

    # 集合の代表を求める
    def find(self, x):
        if self.parent[x] < 0:
            return x
        else:
            # 経路の圧縮
            self.parent[x] = self.find(self.parent[x])
            return self.parent[x]

    # 併合
    def union(self, x, y):
        s1 = self.find(x)
        s2 = self.find(y)
        if s1 != s2:
            self.parent[s2] = s1
            self.count[s1] += self.count[s2]
            self.count[s2] = 0
            return True
        return False

    def count_path(self, x):
        s = self.find(x)
        return self.count[s]

aby.sort(key=lambda x: x[2], reverse=True)
ivw = [(i, v, w) for (w, v, i) in sorted([(w, v, i) for i, (v, w) in enumerate(vw)], reverse=True)]

uf = UnionFind(N)

ans = [0] * Q
idx = 0
for i, v, w in ivw:
    while idx < M:
        a, b, y = aby[idx]
        if y <= w:
            break
        uf.union(a, b)
        idx += 1

    ans[i] = uf.count_path(v)

print(*ans, sep='\n')


