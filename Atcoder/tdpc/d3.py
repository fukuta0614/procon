n, d = [int(i) for i in input().split()]


def yak(x, y):
    a = 0
    while x % y == 0:
        x = x / y
        a += 1
    return a


d2 = yak(d, 2)
d3 = yak(d, 3)
d5 = yak(d, 5)

if 2 ** d2 * 3 ** d3 * 5 ** d5 != d:
    print(0)
    exit()

from collections import defaultdict

dp = defaultdict(int)
dp[(0, 0, 0)] = 1

for i in range(n):
    ndp = list(dp.items())
    for e, cnt in ndp:
        n2, n3, n5 = e
        dp[(min(n2 + 1, d2), n3, n5)] += cnt
        dp[(n2, min(n3 + 1, d3), n5)] += cnt
        dp[(min(n2 + 2, d2), n3, n5)] += cnt
        dp[(n2, n3, min(n5 + 1, d5))] += cnt
        dp[(min(n2 + 1, d2), min(n3 + 1, d3), n5)] += cnt

    print(dp)
print(dp[d2, d3, d5] / (6 ** n))
