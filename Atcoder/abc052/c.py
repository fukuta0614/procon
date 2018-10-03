import math

N = int(input())
mod = 10**9+7

def get_primes(n):
    ps = [0, 0] + [i for i in range(2, n+1)]
    for i in range(2, n+1):
        if ps[i] == 0:
            continue
        for j in range(i * i, n+1, i):
            ps[j] = 0
    return [p for p in ps if p]


prime = get_primes(N)

ans = 1
for p in prime:
    tmp = 0
    for i in range(1, int(math.log(N, p))+1):
        tmp += N // (p**i)

    ans = (ans * (tmp + 1)) % mod

print(ans)



