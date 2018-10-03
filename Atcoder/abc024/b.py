N, T = [int(_) for _ in input().split()]
A = [int(input()) for _ in range(N)]

ans = T * N
for i in range(N-1):
    if A[i] + T > A[i+1]:
        ans -= T - (A[i+1] - A[i])
print(ans)