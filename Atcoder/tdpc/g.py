
from itertools import combinations
from itertools import product
import bisect
import math

s = input()
k = int(input())

x = set()

for n in range(2**len(s)):
    tmp = ""
    for i in range(len(s)):
        if n & 1:
            tmp += s[i]
        n >>= 1

    x.add(tmp)

def factorial(n):
    if n == 0:
        return 1
    return n * factorial(n-1)


# def comb(m, c):
#
#
#     return factorial(n) / factorial(n-c) / factorial(c)

x = sorted(list(x))
# print(x)
# print(x[k])
from collections import defaultdict, Counter
d = defaultdict(int)
for e in x:
    d[len(e)] += 1

print(len(x))
print(d)
# print([ for i in range(10)])

Counter(x)