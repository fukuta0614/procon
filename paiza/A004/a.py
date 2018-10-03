from collections import defaultdict

L, n, m = [int(_) for _ in input().split()]
T = [[int(_) for _ in input().split()] for i in range(m)]

edge = defaultdict(list)

for a, b, c in T:
    edge[a-1].append((b, c, 1))
    edge[a].append((c, b, -1))


for i in range(n):
    edge[i].sort(key=lambda x: x[0])


x, y = 0, L
while True:
    while len(edge[x]) > 0:
        b, c, pos = edge[x].pop()
        if y > b: # (>=いる？）
            y = c
            x += pos
            break

    else:
        print(x+1)
        break
