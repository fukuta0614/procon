mod = 10 ** 9 + 7

N, K = [int(_) for _ in input().split()]

dp1 = [0] * (N + 1)
dp2 = [0] * (N + 1)

dp1[0] = 1
dp1[1] = 0
dp2[1] = 1

for i in range(2, K):
    dp1[i] = (dp1[i - 1] + dp2[i - 1]) % mod
    dp2[i] = (dp1[i - 1] + dp2[i - 1]) % mod


for i in range(K, N + 1):
    dp1[i] = (dp1[i - 1] + dp2[i - 1]) % mod
    dp2[i] = (dp1[i - 1] + dp2[i - 1] - dp1[i - K]) % mod

print(dp2[N])
