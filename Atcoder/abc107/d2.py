N = int(input())
A = [int(_) for _ in input().split()]


import numpy as np

N = 10 ** 5
A = np.load("testcase.npy")
import time
start = time.time()

def sub_problem(x):
    S = [0] * (N + 1)
    for i in range(N):
        S[i + 1] = S[i] + 1 if A[i] >= x else S[i] - 1

    geta = abs(min(S)) + 1
    for i in range(N + 1):
        S[i] += geta

    forward = 0
    size = max(S)
    bit = [0] * (size + 1)
    for s in S:
        i = s
        while i > 0:
            forward += bit[i]
            i -= i & -i

        i = s
        while i <= size:
            bit[i] += 1
            i += i & -i

    return forward >= (M + 1) // 2


M = N * (N + 1) // 2  # (N+1)C2
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

print(sorted_A[inf])
print(time.time() - start)
