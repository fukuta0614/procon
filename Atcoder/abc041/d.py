
from itertools import combinations
from itertools import product
import bisect
import math

N, M = [int(_) for _ in input().split()]
T = [[int(_) for _ in input().split()] for i in range(N)]

dp = [0] * 2**N

