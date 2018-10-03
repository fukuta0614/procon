import heapq

N, M = [int(a) for a in input().split()]

cur, ans = 0, 0
q = []
for i in range(N):
    X, Y = [int(a) for a in input().split()]
    cur += X
    ans = max(ans, cur)

    heapq.heappush(q, X-Y)

    if len(q) == M:
        diff = heapq.heappop(q)
        cur -= diff

print(ans)
