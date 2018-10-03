N, M = [int(_) for _ in input().split()]
Q = [[int(_) for _ in input().split()] for i in range(M)]


class UnionFind1:
    def __init__(self, size):
        # 負の値はルート (集合の代表) で集合の個数
        # 正の値は次の要素を表す
        self.table = [-1 for _ in range(size)]

    # 集合の代表を求める
    def find(self, x):
        if self.table[x] < 0:
            return x
        else:
            # 経路の圧縮
            self.table[x] = self.find(self.table[x])
            return self.table[x]

    # 併合
    def union(self, x, y):
        s1 = self.find(x)
        s2 = self.find(y)
        if s1 != s2:
            if self.table[s1] <= self.table[s2]:
                # 小さいほうが個数が多い
                self.table[s1] += self.table[s2]
                self.table[s2] = s1
            else:
                self.table[s2] += self.table[s1]
                self.table[s1] = s2
            return True
        return False

    def same_check(self, x, y):
        return self.find(x) == self.find(y)


uf = UnionFind1(N)

for t, a, b in Q:
    a -= 1
    b -= 1
    if t == 0:
        uf.union(a, b)
    else:
        if uf.same_check(a, b):
            print("yes")
        else:
            print("no")
