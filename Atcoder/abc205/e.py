
from itertools import combinations
from itertools import product
import bisect
import math

N = 10
M = 10
K = 6

tmp = 0
sm = 0
asdf = [0] * (N+M)
for v in combinations(range(N+M), N):
    sm += 1

    x = [0] * (N+M)
    for e in v:
        x[e] = 1

    # print(x)

    w = b = 0
    for i in range(N+M):
        if x[i] == 1:
            w += 1
        else:
            b += 1

        if w > b + K:
            tmp += 1
            asdf[i] += 1
            break

print(sm)
print(tmp)
print(sm - tmp)

for i in range(N+M):
    print(i+1, asdf[i])