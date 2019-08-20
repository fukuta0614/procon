from itertools import product

N = int(input())

sqrt = int(N ** 0.5)

factorize_result = {}
n = N
for i in range(2, sqrt + 1):
    if n % i == 0:
        factorize_result[i] = 1
        n = n // i
        while n % i == 0:
            factorize_result[i] += 1
            n = n // i
if n > 1:
    factorize_result[n] = 1

ans = 0
vs = [list(range(v+1)) for v in factorize_result.values()]
for indices in product(*vs, repeat=1):

    tmp = 1
    for i, (k, v) in enumerate(factorize_result.items()):
       tmp *= k ** indices[i]

    tmp -= 1
    if tmp == 0:
        continue

    if N % tmp == N // tmp:
        ans += tmp

print(ans)





