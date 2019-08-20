N, M = map(int, input().split())
A = [int(input()) for i in range(N)]

mod = int(1e9) + 7

dp_sum = [0] * (N+2)
dp_sum[-1] = 1

l = 0
used = [False] * (M+1)
for i in range(N):

    while l < i and used[A[i]]:
        used[A[l]] = False
        l += 1

    used[A[i]] = True
    ans = (dp_sum[i-1] - dp_sum[l-2]) % mod
    dp_sum[i] = (dp_sum[i-1] + ans) % mod

print(ans)