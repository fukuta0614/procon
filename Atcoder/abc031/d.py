from itertools import product

K, N = [int(_) for _ in input().split()]
T = [input().split() for i in range(N)]

def valid(p):
    goro = [''] * K
    for v, w in T:
        idx = 0
        for n in v:
            n = int(n)
            if goro[n - 1]:
                if goro[n - 1] != w[idx:idx + p[n - 1]]:
                    return False
            else:
                goro[n - 1] = w[idx:idx + p[n - 1]]
            idx += p[n - 1]

        a = ''
        for n in v:
            a += goro[int(n) - 1]
        if a != w:
            return False

    else:
        for x in goro:
            print(x)
        exit()

for p in product(range(1,4), repeat=K):
    valid(p)
