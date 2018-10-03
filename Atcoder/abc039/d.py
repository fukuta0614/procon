H, W = [int(_) for _ in input().split()]
T = [list(input()) for i in range(H)]

dxy8 = [(0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1), (-1, 0), (-1, 1)]

X = [T[i][:] for i in range(H)]

for i in range(H):
    for j in range(W):
        if T[i][j] == '.':
            for dx, dy in dxy8:
                nx, ny = i + dx, j + dy
                if 0 <= nx < H and 0 <= ny < W:
                    X[nx][ny] = '.'

for i in range(H):
    for j in range(W):
        if T[i][j] == '#' and X[i][j] != '#':
            flag = True
            for dx, dy in dxy8:
                nx, ny = i + dx, j + dy
                if 0 <= nx < H and 0 <= ny < W:
                    if X[nx][ny] == '#':
                        flag = False
            if flag:
                print('impossible')
                exit()

print('possible')
for i in range(H):
    print(*X[i], sep='')
