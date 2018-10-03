
N, A = [int(_) for _ in input().split()]
x = sorted([int(_) for _ in input().split()])

dp = [[0] * (sum(x)+1) for j in range(N+1)]

dp[0][0] = 1
for i in range(1, N+1):
    for j in list(range(1, N+1))[::-1]:
        for k in list(range(x[i-1], sum(x[:i])+1))[::-1]:
            dp[j][k] += dp[j-1][k - x[i-1]]

print(sum([dp[i][i*A] for i in range(1, N+1) if i*A <= sum(x)]))
