N, M = [int(_) for _ in input().split()]
T = [[int(_) for _ in input().split()] for i in range(M)]

E = []
for a, b, c in T:
    E.append((a - 1, b - 1, c))

min_V = -1000000000 * 2000
scores = [min_V] * N
scores[0] = 0

for i in range(N):
    for a, b, c in E:
        if scores[b] >= scores[a] + c:
            continue
        scores[b] = scores[a] + c

ans = scores[N - 1]

for a, b, c in E:
    if scores[b] >= scores[a] + c:
        continue
    scores[b] = scores[a] + c

if ans != scores[N-1]:
    print("inf")
else:
    print(scores[N - 1])
