from itertools import combinations

N, M, P, Q, R = [int(_) for _ in input().split()]
T = [[int(_) for _ in input().split()] for i in range(R)]

r = [[0] * M for i in range(N)]
for x, y, z in T:
    r[x-1][y-1] = z

res = 0
for p in combinations(range(N), P):
    value = [r[x] for x in range(N) if x in p]
    value = list(map(sum, zip(*value)))
    # value = [sum(v) for v in zip(*value)]
    res = max(res, sum(sorted(value)[-Q:]))

print(res)