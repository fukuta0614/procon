import heapq

H, W, T = [int(_) for _ in input().split()]
b = [[x for x in input()] for i in range(H)]

inf = 1
sup = 10 ** 9
xs, ys = [(i, j) for i in range(H) for j in range(W) if b[i][j] == 'S'][0]
xg, yg = [(i, j) for i in range(H) for j in range(W) if b[i][j] == 'G'][0]

while sup - inf > 1:

    med = (sup + inf) // 2

    dist = [[float('inf')] * W for i in range(H)]
    dist[xs][ys] = 0
    q = [(0, xs, ys)]
    while len(q) > 0:
        cost, x, y = heapq.heappop(q)

        if dist[x][y] < cost:
            continue

        for dx, dy in [(0,1), (0,-1),(1,0),(-1,0)]:
            nx = x + dx
            ny = y + dy
            if 0 <= nx < H and 0 <= ny < W:
                tmp = cost + (med if b[nx][ny] == '#' else 1)
                if tmp < dist[nx][ny]:
                    dist[nx][ny] = tmp
                    heapq.heappush(q, (tmp, nx, ny))

    if dist[xg][yg] <= T:
        inf = med
    else:
        sup = med

print(inf)
