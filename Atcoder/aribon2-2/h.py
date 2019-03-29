
from itertools import combinations, permutations
from itertools import product
import bisect
import math

N, K = [int(_) for _ in input().split()]
S = input()

ans = S
for perm in permutations(S):

    sm = sum([1 for i in range(N) if S[i] != perm[i]])
    if sm <= K and ''.join(perm) < ans:
        ans = ''.join(perm)

print(ans)