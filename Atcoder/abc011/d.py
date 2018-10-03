def main1():
    from itertools import product

    N, D = [int(_) for _ in input().split()]
    X, Y = [int(_) for _ in input().split()]

    jump = [(0, D), (0, -D), (-D, 0), (D, 0)]
    prob = 0
    count = 0
    for p in product(range(4), repeat=N):
        x, y = 0, 0
        for r in p:
            x += jump[r][0]
            y += jump[r][1]
        if x == X and y == Y:
            prob += 1
        count += 1
    print(prob / count)


def main2():
    N, D = [int(_) for _ in input().split()]
    X, Y = [int(_) for _ in input().split()]

    if X % D > 0 or Y % D > 0:
        print(0)
        exit()

    X, Y = abs(X // D), abs(Y // D)

    jump = [(0, 1), (0, -1), (-1, 0), (1, 0)]
    dp = dict()

    def prob(x, y, n):
        if (x, y, n) in dp:
            return dp[(x, y, n)]
        else:
            if n == 1:
                if (x, y) in jump:
                    return 1 / 4
                else:
                    return 0
            else:
                p = (prob(x, y + 1, n - 1) + prob(x, y - 1, n - 1) + prob(x - 1, y, n - 1) + prob(x + 1, y, n - 1)) / 4
                dp[(x, y, n)] = p
                return p

    print(prob(X, Y, N))


def main3():
    N, D = [int(_) for _ in input().split()]
    X, Y = [int(_) for _ in input().split()]

    if X % D > 0 or Y % D > 0:
        print(0)
        exit()

    X, Y = abs(X // D), abs(Y // D)

    jump = [(0, 1), (0, -1), (-1, 0), (1, 0)]
    dp = dict()

    def prob(dist, n):
        if (dist, n) in dp:
            return dp[(dist, n)]
        else:
            if n == 1:
                if dist == 1:
                    return 1
                else:
                    return 0
            else:
                p = (prob(dist + 1, n - 1) / 2 + prob(dist - 1, n - 1) / 2) * (dist - 1) / dist
                p += (prob(dist + 1, n - 1) / 2 + prob(dist - 1, n - 1) / 2) * (dist - 1) / dist
                dp[(dist, n)] = p
                return p

    print(prob(X + Y, N) / (4 * (X + Y)))


def main4():
    import math

    N, D = [int(_) for _ in input().split()]
    X, Y = [int(_) for _ in input().split()]

    if X % D > 0 or Y % D > 0:
        print(0)
        exit()
    X, Y = abs(X // D), abs(Y // D)
    if (N - (X + Y)) % 2 > 0:
        print(0)
        exit()
    k = (N - X - Y) // 2

    res = 0
    for up in range(k + 1):
        right = k - up
        tmp = math.factorial(N)
        tmp //= math.factorial(X + up)
        tmp //= math.factorial(up)
        tmp //= math.factorial(Y + right)
        tmp //= math.factorial(right)
        res += tmp

    print(res / 4 ** N)


main2()

# main4()
