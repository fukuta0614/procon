def main1():
    N, M = [int(_) for _ in input().split()]

    dp = [[0 if i == j else float('inf') for j in range(N)] for i in range(N)]
    for _ in range(M):
        a, b, t = [int(x) for x in input().split()]
        dp[a-1][b-1] = t
        dp[b-1][a-1] = t

    for k in range(N):
        for i in range(N):
            for j in range(N):
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j])

    res = float('inf')
    for i in range(N):
        res = min(res, max(dp[i]))

    print(res)
