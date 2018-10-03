N, M, Q = [int(_) for _ in input().split()]
T = [[int(_) for _ in input().split()] for i in range(M)]
Q = [[int(_) for _ in input().split()] for i in range(Q)]

train_map = [[0] * (N + 1) for i in range(N + 1)]
for l, r in T:
    train_map[l][r] += 1

cumsum = [[0] * (N + 1) for i in range(N + 1)]
for i in range(1, N + 1):
    for j in range(1, N + 1):
        cumsum[i][j] = train_map[i][j] + cumsum[i][j - 1] + cumsum[i - 1][j] - cumsum[i - 1][j - 1]

for p, q in Q:
    print(cumsum[q][q] - cumsum[p-1][q])
