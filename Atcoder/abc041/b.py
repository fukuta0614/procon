
from itertools import combinations
from itertools import product
import bisect
import math

A, B, C = [int(_) for _ in input().split()]
mod = 10 ** 9 + 7

print(A*B*C % mod)