from itertools import combinations

N, K = [int(_) for _ in input().split()]

digits = set(range(2 * N))

ans = 0
if N <= K:
    for a in combinations(range(2 * N), N):
        b = digits - set(a)
        sum_ = 0
        A = sorted(a)
        B = sorted(b)
        x = sum([abs(A[i] - B[i]) for i in range(N)])
        if x <= K:
            ans += 1
print(ans)
