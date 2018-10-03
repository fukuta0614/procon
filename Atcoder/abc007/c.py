import heapq

R, C = [int(_) for _ in input().split()]
sy, sx = [int(_)-1 for _ in input().split()]
gy, gx = [int(_)-1 for _ in input().split()]

c = [list(input()) for i in range(R)]

q = [(sy, sx, 0)]
dist = [[float('inf')] * C for _ in range(R)]
dist[sy][sx] = 0

while len(q) > 0:
    y, x, cost = heapq.heappop(q)

    if dist[y][x] < cost:
        continue

    for dy, dx in [(0, 1), (0, -1), (-1, 0), (1, 0)]:
        ny, nx = y + dy, x + dx
        if c[ny][nx] == '.':
            if cost + 1 < dist[ny][nx]:
                dist[ny][nx] = cost + 1
                heapq.heappush(q, (y + dy, x + dx, cost + 1))

print(dist[gy][gx])
