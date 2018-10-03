from itertools import combinations
from itertools import product
import bisect
import math

mod = 10 ** 9 + 7
N, M = [int(_) for _ in input().split()]

fact = {}


def factorization(n):
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            fact[i] = 1
            n = n // i
            while n % i == 0:
                fact[i] += 1
                n = n // i
    if n > 1:
        fact[n] = 1


factorization(M)
print(fact)

max_length = 0
for k,v in fact.items():
    max_length += v

ans = 0
# for i in range(1, max_length + 1):
