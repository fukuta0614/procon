
from itertools import combinations
from itertools import product
import bisect
import math

N, K = [int(_) for _ in input().split()]
S = input()

if K == N:
    s = S[:K-1] + S[K-1].lower()
else:
    s = S[:K-1] + S[K-1].lower() + S[K:]

print(s)