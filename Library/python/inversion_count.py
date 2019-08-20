# N = int(input())
# A = [int(_) for _ in input().split()]

N = 20
A = [19, 11, 10, 7, 8, 9, 17, 18, 20, 4, 3, 15, 16, 1, 5, 14, 6, 2, 13, 12]


class BIT:
    # index 1~
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)

    def sum(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s

    def add(self, i, x):
        while i <= self.size:
            self.tree[i] += x
            i += i & -i

inv = 0
bit = BIT(max(A))
for s in reversed(A):
    inv += bit.sum(s)
    bit.add(s, 1)
    print(s, bit.tree, bit.sum(s))

print(inv)