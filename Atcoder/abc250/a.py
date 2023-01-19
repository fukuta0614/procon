H, W = [int(_) for _ in input().split()]
R, C = [int(_) for _ in input().split()]
R -= 1
C -= 1

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def is_inside(i, j, H, W):
    return 0 <= i < H and 0 <= j < W


ans = 0
for k in range(4):
    if is_inside(R + dx[k], C + dy[k], H, W):
        ans += 1

print(ans)
