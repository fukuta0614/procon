N, D, K = [int(_) for _ in input().split()]

LR = [[int(_) - 1 for _ in input().split()] for _ in range(D)]
ST = [[int(_) - 1 for _ in input().split()] for _ in range(K)]

p = []
for s, t in ST:
    p.append(s)

ans = [0] * K
for i in range(D):
    l, r = LR[i]
    for k in range(K):
        s, t = ST[k]
        if p[k] == t:
            continue

        if l <= p[k] <= r:
            if l <= t <= r:
                p[k] = t
                ans[k] = i
            elif t - s > 0:
                p[k] = r
            elif t - s < 0:
                p[k] = l

for k in range(K):
    print(ans[k] + 1)

