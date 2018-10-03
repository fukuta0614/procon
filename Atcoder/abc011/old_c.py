N = int(input())
NG1 = int(input())
NG2 = int(input())
NG3 = int(input())

if N == NG1 or N == NG2 or N == NG3:
    print("NO")
else:
    dp = [101] * (N + 3)
    dp[N] = 0
    for i in range(0, N)[::-1]:
        if i == NG1 or i == NG2 or i == NG3:
            continue
        dp[i] = min(dp[i + 1] + 1, dp[i + 2] + 1, dp[i + 3] + 1)

    res = "YES" if dp[0] <= 100 else "NO"
    print(res)
