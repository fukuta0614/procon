N = int(input())
A = [int(_) for _ in input().split()]


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


def sub_problem(x):
    S = [0] * (N + 1)
    for i in range(N):
        S[i + 1] = S[i] + 1 if A[i] >= x else S[i] - 1

    geta = abs(min(S)) + 1
    for i in range(N + 1):
        S[i] += geta

    forward = 0
    bit = BIT(max(S))
    for s in S:
        forward += bit.sum(s)
        bit.add(s, 1)

    # if (forward >= (M + 1) // 2) == (forward >= M // 2):
    #     print("OK")
    # else:
    #     print("dame")
    return forward >= M // 2


def solve(N, A):
    sorted_A = sorted(A)

    inf = 0
    sup = N
    while sup - inf > 1:
        mid = (sup + inf) // 2
        x = sorted_A[mid]

        if sub_problem(x):
            inf = mid
        else:
            sup = mid

    # print(sorted_A[inf])
    return sorted_A[inf]


def guchoku(N, A):
    from itertools import combinations_with_replacement

    m = sorted([sorted(A[i:j + 1])[(j + 1 - i) // 2] for i, j in combinations_with_replacement(range(N), 2)])
    print(m)
    ans = m[len(m) // 2]
    return ans


if __name__ == '__main__':
    import numpy as np

    import time
    # A = [2, 4, 5, 1, 5]
    # N = 5
    # M = N * (N + 1) // 2
    # print(guchoku(N, A))
    # print(solve(N, A))
    for N in range(1, 200):
        M = N * (N + 1) // 2  # (N+1)C2
        if M % 2 == 1:
            for i in range(10000):
                A = np.random.randint(1, N + 1, N)
                print(N, A, M)
                if guchoku(N, A) != solve(N, A):
                    print("!!!")
                    exit()
