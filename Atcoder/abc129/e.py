
MOD = 1e09 + 7

N = int(input())
tmp = N
d = 0
while tmp:
    tmp >>= 1
    d += 1


dp = [[0]*2 for i in range(100002)]
dp[0][0] = 1
for i in range(d):

    if (N >> (d - i)) & 1:
        dp[i + 1][0] += dp[i][0] % MOD
        dp[i + 1][1] += dp[i][1] % MOD

    # else:
    #     dp[i + 1][0] += dp[i][k] % MOD

    # dp[i + 1][k | | (d != n)] += dp[i][k] % MOD

    # for k in range(2):
    #
    #     if (N >> (d-i)) & 1:
    #         dp[i+1][k||(d!=n)] += dp[i][k] % MOD
    #     else:

print(0^7, 0+7)
