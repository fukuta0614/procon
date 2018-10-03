
N, Q = [int(_) for _ in input().split()]
T = [[int(_) for _ in input().split()] for i in range(Q)]

ans = [0] * N
for l, r, t in T:
    for i in range(l-1,r):
        ans[i] = t

for x in ans:
    print(x)
