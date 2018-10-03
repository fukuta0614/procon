
N, Ma, Mb = [int(_) for _ in input().split()]
T = [[int(_) for _ in input().split()] for i in range(N)]

dp = [[float('inf') for i in range(401)] for i in range(401)]
dp[0][0] = 0

sum_a = 0
sum_b = 0
for x in range(N):
    a, b, c = T[x]
    sum_a += a
    sum_b += b
    for i in list(range(a, sum_a+1))[::-1]:
        for j in list(range(b, sum_b+1))[::-1]:
            dp[i][j] = min(dp[i][j], dp[i-a][j-b]+c)

ans = float('inf')
for i in range(1, sum_a+1):
    for j in range(1, sum_b+1):
        if i * Mb == j * Ma:
            ans = min(ans, dp[i][j])

print(ans if ans != float('inf') else -1)