N = int(input())
a = [int(_) for _ in input().split()]

import sys
sys.setrecursionlimit(10**6)

memo = {}
def dp(n):
    if n in memo:
        return memo[n]

    if n == 0:
        res = 0
    elif n == 1:
        res = abs(a[1] - a[0])
    else:
        res = min(dp(n - 1) + abs(a[n] - a[n - 1]), dp(n - 2) + abs(a[n] - a[n - 2]))
    memo[n] = res
    return memo[n]

print(dp(N - 1))
