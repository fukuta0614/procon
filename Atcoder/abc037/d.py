H, W = [int(_) for _ in input().split()]
T = [[int(_) for _ in input().split()] for i in range(H)]

import sys
sys.setrecursionlimit(10**7)
mod = 10**9 + 7
memo = {}

def count(x, y):
    if (x, y) in memo:
        return memo[(x, y)]
    res = 1
    for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
        nx = x + dx
        ny = y + dy
        if 0 <= nx < H and 0 <= ny < W:
            if T[nx][ny] > T[x][y]:
                res += count(nx, ny)
    memo[(x, y)] = res % mod
    return memo[(x, y)]


ans = 0
for x in range(H):
    for y in range(W):
        ans += count(x, y)

print(ans % mod)
