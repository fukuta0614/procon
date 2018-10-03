N, K = [int(_) for _ in input().split()]
T = [[int(_) for _ in input().split()] for i in range(N)]

inf = 0
sup = 100
for _ in range(100):
    med = (inf + sup) / 2
    salt = 0
    amount = 0
    for w, p in sorted(T, key=lambda x: x[0] * (x[1]-med))[-K:]:
        salt += w * p / 100
        amount += w
    ans = 100 * salt / amount
    if ans > med:
        inf = med
    else:
        sup = med

print(ans)

