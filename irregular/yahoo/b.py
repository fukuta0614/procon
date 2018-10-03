
from itertools import combinations
from itertools import product
import bisect
import math

N, K = [int(_) for _ in input().split()]
A = [int(_) for _ in input().split()]

ans = sum(sorted(A)[:K]) + sum(list(range(K)))
print(ans)