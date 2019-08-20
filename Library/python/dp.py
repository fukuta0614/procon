n = int(input())
M = [[int(_) for _ in input().split()] for _ in range(n)]

dp = [[0 for i in range(n)] for i in range(n)]

for m in range(1, n):
    for i in range(0, n-m):
        opt = float('inf')
        for k in range(i, i+m):
            opt = min(opt, dp[i][k] + dp[k + 1][i+m] + M[i][0] * M[k][1] * M[i+m][1])
        dp[i][i+m] = opt

print(dp[0][-1])
