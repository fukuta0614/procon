from itertools import combinations

N = int(input())
D = [[int(_) for _ in input().split()] for i in range(N)]
Q = int(input())
P = [int(input()) for _ in range(Q)]

imos = [[0] * (N+1) for _ in range(N+1)]
for i in range(N):
    for j in range(N):
        imos[i][j] = imos[i - 1][j] + imos[i][j - 1] - imos[i - 1][j - 1] + D[i][j]

a = [0] * (N**2 + 1)
for xa, xb in combinations(range(N + 1), 2):
    for ya, yb in combinations(range(N + 1), 2):
        S = imos[xb - 1][yb - 1] - imos[xa - 1][yb - 1] - imos[xb - 1][ya - 1] + imos[xa - 1][ya - 1]
        s = (xb - xa) * (yb - ya)
        a[s] = max(a[s], S)

for q in range(Q):
    print(max(a[:P[q]+1]))
