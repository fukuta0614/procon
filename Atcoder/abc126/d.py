
from itertools import combinations
from itertools import product
import bisect
import math

# N = int(input())
# N, K = [int(_) for _ in input().split()]
# T = [[int(_) for _ in input().split()] for i in range(N)]

sm = 0
for a in [0,1,2,3,5,6,7,4,7,6,5,3,2,1,0]:
    sm ^= a

print(sm)