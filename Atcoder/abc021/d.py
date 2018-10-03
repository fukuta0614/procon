mod = 10 ** 9 + 7

n = int(input())
k = int(input())

factorial = [1] * (n+k)
for i in range(1, (n+k)):
    factorial[i] = i * factorial[i - 1] % mod


def calc(n, k):
    a = factorial[n] % mod
    b = (factorial[k] * factorial[n - k]) % mod
    b_ = pow(b, mod - 2, mod)

    return (a * b_) % mod

print(calc(n + k - 1, k))
