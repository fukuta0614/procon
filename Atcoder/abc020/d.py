import math

N, K = [int(_) for _ in input().split()]
mod = 10**9+7


def calc_divisor(K):
    a = []
    b = []
    for i in range(1, int(math.sqrt(K))+1):
        if K % i == 0:
            if i == int(math.sqrt(K)):
                a.append(i)
            else:
                a.append(i)
                b.append(K//i)

    return a + b[::-1]


def euclidean_algorithm(m,n):
    if m % n == 0:
        return n
    else:
        return euclidean_algorithm(n,m%n)

res = [0] * K
res[0] = K
for i in range(1, K):
    res[i] = euclidean_algorithm(K, i)

n, r = N // K, N % K
ans = 0
for i in range(K):
    if i == 0:
        ans += ((n+1)*K*n // 2) % mod
    else:
        ans += ((i + (n-1)*K + i) * n // 2 * K // res[i]) % mod
for i in range(1, r+1):
    ans += ((i + n * K) * K // res[i]) % mod

print(ans % mod)
