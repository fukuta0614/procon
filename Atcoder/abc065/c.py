N, M = [int(x) for x in input().split()]
N, M = min(N, M), max(N, M)

mod = 10 ** 9 + 7

def factorial(n):
    ans = 1
    for i in range(1, n + 1):
        ans = ans * i % mod
    return ans


if N == M:
    ans = 2 * factorial(N) * factorial(M) % mod
elif N + 1 == M:
    ans = factorial(N) * factorial(M) % mod
else:
    ans = 0

print(ans)
