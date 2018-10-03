def main1():
    W = int(input())
    N, K = [int(_) for _ in input().split()]
    T = [[int(_) for _ in input().split()] for i in range(N)]
    T.sort()
    dp = [[0] * (K+1) for i in range(W+1)]

    tmp = 0
    for a, b in T:
        tmp = min(tmp+a, W)
        for w in list(range(a, tmp+1))[::-1]:
            for k in list(range(1, K + 1))[::-1]:
                dp[w][k] = max(dp[w][k], dp[w-a][k-1] + b)

    print(max([max(x) for x in dp]))


W = int(input())
N, K = [int(_) for _ in input().split()]
T = [[int(_) for _ in input().split()] for i in range(N)]
T.sort(key=lambda x: x[1]/x[0], reverse=True)


w, k, value = 0, 0, 0
for a, b in T:
    if w + a <= W and k < K:
        w += a
        value += b
        k += 1
    elif k == K:
        break
    else:
        continue

print(value)
