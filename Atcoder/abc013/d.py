import bisect

N, M, D = [int(_) for _ in input().split()]
A = [int(_) - 1 for _ in input().split()]

amida = list(range(N))
for i in range(M):
    idx = A[i]
    amida[idx], amida[idx + 1] = amida[idx + 1], amida[idx]

amida = sorted(range(len(amida)), key=amida.__getitem__)
q = list(range(N))
block = []
while len(q) > 0:
    s = q.pop(0)
    tmp = [s]
    x = s
    while True:
        x = amida[x]
        if x == s:
            break
        else:
            idx = bisect.bisect_left(q, x)
            q.pop(idx)
            tmp.append(x)
    block.append(tmp)

ans = [0] * N
for b in block:
    loop = len(b)
    shift = D % loop
    for i in range(len(b)):
        ans[b[i]] = b[(i + shift) % loop]

for x in ans:
    print(x+1)
