mod = 10 ** 9 + 7
n = int(input())
l = len(input())
dp = [[0] * (n + 2) for j in range(n + 1)]

for i in range(n + 1):
    for j in range(i + 1):
        if i == 0:
            dp[i][j] = 1
        elif j == 0:
            dp[i][j] = (dp[i - 1][1] * 2 + dp[i - 1][0]) % mod
        else:
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1] * 2) % mod

print(dp[n][l])
