from collections import defaultdict
import queue

# N = 7
# a,b = 1,7
# M = 8
# xy = [[1, 2], [1, 3], [4, 2], [4, 3], [4, 5], [4, 6], [7, 5], [7, 6]]

N = int(input())
a, b = [int(_) for _ in input().split()]
M = int(input())
xy = [[int(_) for _ in input().split()] for i in range(M)]

mod = 10**9 + 7

road = defaultdict(list)
for i, j in xy:
    road[i].append(j)
    road[j].append(i)

dist = {i: float('inf') for i in range(1, N + 1)}
dist[a] = 0
count = {i: -1 for i in range(1, N + 1)}
count[a] = 1
q = queue.Queue()
q.put((0, a))

while not q.empty():
    cost, src = q.get()

    for d in road[src]:
        if count[d] == -1:
            count[d] = count[src]
            dist[d] = cost + 1
            q.put((dist[d], d))
        elif dist[d] == cost + 1:
            count[d] += count[src]
            count[d] %= mod
print(count[b])