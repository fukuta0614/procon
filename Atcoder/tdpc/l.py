N = int(input())
F = [[int(_) for _ in input().split()] for i in range(N)]

S = [[0] * (N + 1) for _ in range(N)]
for i in range(N):
    for j in range(N):
        S[i][j + 1] = S[i][j] + F[i][j]

dp = [[0] * N for _ in range(N)]
for i in range(N):
    tmp = -float("inf")
    for j in range(i + 1):
        tmp = max(tmp, dp[i - 1][j])
        dp[i][j] = tmp + (S[i][i] - S[i][j])

print(2 * max(dp[-1]))