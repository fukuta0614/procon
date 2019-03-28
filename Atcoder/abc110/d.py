mod = 10 ** 9 + 7
N, M = [int(_) for _ in input().split()]

MAX_N = 10 ** 5 + 100

factorize_result = {}
def factorization(n):
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            factorize_result[i] = 1
            n = n // i
            while n % i == 0:
                factorize_result[i] += 1
                n = n // i
    if n > 1:
        factorize_result[n] = 1


factorial = [1] * MAX_N
def calc_factorial():
    for i in range(1, MAX_N):
        factorial[i] = i * factorial[i - 1] % mod


def comb(n, k):
    a = factorial[n] % mod
    b = (factorial[k] * factorial[n - k]) % mod
    b_ = pow(b, mod - 2, mod)
    return (a * b_) % mod


# 素因数分解
factorization(M)

# 階乗を用意
calc_factorial()

ans = 1
for k, v in factorize_result.items():
    ans *= comb(N + v - 1, v) % mod

print(ans % mod)
