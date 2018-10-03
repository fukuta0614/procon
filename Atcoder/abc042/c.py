from itertools import combinations
from itertools import product
import bisect
import math
import sys

sys.setrecursionlimit(10 ** 6)

N, X, Y, Z = [int(_) for _ in input().split()]
mod = 10 ** 9 + 7


def comb(n, k):
    a = math.factorial(n) % mod
    b = (math.factorial(k) * math.factorial(n - k)) % mod
    b_ = pow(b, mod - 2, mod)
    return (a * b_) % mod


res = [0, 0, 0]
for l in range(3, min(N, sum((X, Y, Z))) + 1):
    # tmp1 = (N-l+1) * 10**(N-l) % mod
    x = 0
    tmp2 = 0
    for y, z in combinations(range(1, l), 2):
        if X >= y - x and Y >= z - y and Z >= l - z:
            tmp2 += comb(X - 1, y - x - 1) * comb(Y - 1, z - y - 1) * comb(Z - 1, l - z - 1)
    res.append(tmp2 % mod)

print(res)

memo = {}


def func(L):
    if L in memo:
        return memo[L]
    if L <= 3:
        return res[L]
    ans = 0
    for l in range(3, min(L, sum((X, Y, Z))) + 1):
        tmp = 0
        for i in range(L - l + 1):
            left = i
            right = L - i - l
            p = (10 ** left - func(left)) % mod
            q = (10 ** right - func(right)) % mod
            tmp += p * q % mod
        ans += tmp * res[l] % mod

    memo[L] = ans % mod
    print(memo)
    return memo[L]


print(func(N))
