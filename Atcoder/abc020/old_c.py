import heapq

H, W, T = [int(_) for _ in input().split()]
s = [[_ for _ in input()] for i in range(H)]

# H, W, T = 3, 4, 7
# s = [['S', '#', '#', 'G'], ['.', '#', '#', '.'], ['.', '.', '#', '.']]

xs, ys = next((x, y) for x in range(H) for y in range(W) if s[x][y] == 'S')
xg, yg = next((x, y) for x in range(H) for y in range(W) if s[x][y] == 'G')

inf = 0
sup = T

while sup - inf > 1:

    med = (sup + inf) // 2

    distance = [[float('inf') for j in range(W)] for i in range(H)]
    distance[xs][ys] = 0
    q = [(0, (xs, ys))]

    while len(q) > 0:
        cost, (x, y) = heapq.heappop(q)

        if distance[x][y] < cost:
            continue

        for dx, dy in [(-1, 0), (0, -1), (0, 1), (1, 0)]:
            if 0 <= x + dx < H and 0 <= y + dy < W:
                tmp = cost + (med if s[x + dx][y + dy] == '#' else 1)
                if tmp < distance[x + dx][y + dy]:
                    distance[x + dx][y + dy] = tmp
                    heapq.heappush(q, (tmp, (x + dx, y + dy)))

    if distance[xg][yg] > T:
        sup = med
    else:
        inf = med

print(inf)

