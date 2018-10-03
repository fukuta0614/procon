def main1():

    from itertools import combinations

    N, M = [int(_) for _ in input().split()]
    xy = [[int(_) - 1 for _ in input().split()] for i in range(M)]

    r = [[1 if i == j else 0 for i in range(N)] for j in range(N)]

    for x, y in xy:
        r[x][y] = r[y][x] = 1

    cone_num = [0 for i in range(N)]
    for i in range(N):
        for n in range(sum(r[i])):
            cone_num[n] += 1

    for i in list(range(N))[::-1]:
        if cone_num[i] >= i+1:
            max_cone = i+1
            break

    sup = max_cone + 1
    inf = 1
    while sup - inf > 1:
        m = (inf + sup) // 2

        for c in combinations(range(N), m):
            flag = True
            for x in c:
                for y in c:
                    if not r[x][y]:
                        flag = False
            if flag:
                break
        if flag:
            inf = m
        else:
            sup = m

    print(inf)

def main2():

    from itertools import product

    N, M = [int(_) for _ in input().split()]
    xy = [[int(_) - 1 for _ in input().split()] for i in range(M)]

    r = [[1 if i == j else 0 for i in range(N)] for j in range(N)]
    for x, y in xy:
        r[x][y] = r[y][x] = 1

    for p in sorted(list(product(range(2), repeat=N)), key=lambda x: -sum(x)):
        flag = True
        for x in range(N):
            for y in range(N):
                if p[x] and p[y] and not r[x][y]:
                    flag = False
                    break
            if not flag:
                break
        if flag:
            res = sum(p)
            break
    print(res)

main2()
