import heapq
from functools import reduce

H, W, K = [int(_) for _ in input().split()]
T = [[int(_) for _ in input()] for i in range(H)]

used = [[False for _ in range(W)] for _ in range(H)]


def manhattan(i, j, x, y):
    return abs(x - i) + abs(y - j)


pieces = []
for i in range(H):
    for j in range(W):
        if used[i][j] or T[i][j] == 0:
            continue

        q = [(-T[i][j], i, j)]
        piece = []
        while len(q) > 0:
            cost, x, y = heapq.heappop(q)

            if not used[x][y]:
                piece.append((-cost, x, y))
                used[x][y] = True

            if len(piece) == 8:
                pieces.append(piece)
                break

            for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                nx = x + dx
                ny = y + dy
                if 0 <= nx < H and 0 <= ny < W and manhattan(i, j, nx, ny) < 8 and not used[nx][ny]:
                    v = T[nx][ny]
                    if v == 0:
                        continue
                    heapq.heappush(q, (-v, nx, ny))

print(len(pieces))
for piece in pieces:
    for v, x, y in piece:
        print(x+1, y+1)
