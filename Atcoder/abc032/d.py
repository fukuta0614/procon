N, W = [int(_) for _ in input().split()]
T = [[int(_) for _ in input().split()] for i in range(N)]

memo = {}
def napsac(n, w):
    if (n, w) in memo:
        return memo[(n, w)]

    if n == 0:
        res = 0

    elif T[n-1][1] > w:
        res = napsac(n - 1, w)

    else:
        res = max(napsac(n - 1, w), napsac(n - 1, w - T[n - 1][1]) + T[n - 1][0])

    memo[(n,w)] = res
    return memo[(n,w)]


def dp_napsac(N, W):


    dp = [0] * (W+1)

    for v, w in T:
        for i in list(range(w, W+1))[::-1]:
            dp[i] = max(dp[i], dp[i - w] + v)

    return dp[-1]

def dp_napsac_value(N, V):
    dp = [float('inf')] * (V + 1)
    dp[0] = 0
    for v, w in T:
        for i in list(range(v, V + 1))[::-1]:
            dp[i] = min(dp[i], dp[i - v] + w)

    return max([v for v, w in enumerate(dp) if w <= W])

max_V = max([v for v, w in T])
max_W = max([w for v, w in T])

if N <= 30:
    res = napsac(N, W)
elif max_V <= 1000:
    V = N * max_V
    res = dp_napsac_value(N, V)
else:
    if max_W * N < W:
        res = sum([v for v, w in T])
    else:
        res = dp_napsac(N, W)
print(res)