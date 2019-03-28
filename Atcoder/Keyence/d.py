
N, M = [int(_) for _ in input().split()]
A = [int(_) for _ in input().split()]
B = [int(_) for _ in input().split()]

import numpy as np

A_ = reversed(np.argsort(A))
B_ = reversed(np.argsort(B))
row_res = [0] * N
col_res = [0] * M

ans = 1
for x in reversed(range(1, N * M + 1)):

    tmp1 = 0
    for idx in A_:
        if A[idx] == x:
            tmp1 = 1
            break

        elif A[idx] < x:
            break

        tmp1 += 1

    tmp2 = 0
    for idx in B_:
        if B[idx] == x:
            tmp2 = 1
            break
        tmp2 += 1

    ans *= tmp1 * tmp2





