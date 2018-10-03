H, W, N = [int(_) for _ in input().split()]
T = [["."] * (W + 2) for _ in range(H + 2)]
for i in range(H):
    line = input().split()
    for j in range(W):
        T[i + 1][j + 1] = line[j]
Q = [[int(_) for _ in input().split()] for i in range(N)]


def check_cell(i, j, a1, b1, a2, b2):
    if (i == a1 and j == b1) or (i == a2 and j == b2):
        return True

    if T[i][j] != ".":
        return False

    return True


def check_p1(p, a1, b1, a2, b2):
    j = b1
    for i in (range(a1, p) if a1 < p else range(a1, p, -1)):  # a1 ~ p-1
        if not check_cell(i, j, a1, b1, a2, b2):
            return False

    i = p
    for j in (range(b1, b2 + 1) if b1 < b2 else range(b1, b2 - 1, -1)):  # b1 ~ b2
        if not check_cell(i, j, a1, b1, a2, b2):
            return False

    j = b2
    for i in (range(a2, p) if a2 < p else range(a2, p, -1)):  # a2 ~ p-1
        if not check_cell(i, j, a1, b1, a2, b2):
            return False

    return True


def check_p2(p, a1, b1, a2, b2):
    i = a1
    for j in (range(b1, p) if b1 < p else range(b1, p, -1)):  # b1 ~ p-1
        if not check_cell(i, j, a1, b1, a2, b2):
            return False

    j = p
    for i in (range(a1, a2 + 1) if a1 < a2 else range(a1, a2 - 1, -1)):  # a1 ~ a2
        if not check_cell(i, j, a1, b1, a2, b2):
            return False

    i = a2
    for j in (range(b2, p) if b2 < p else range(b2, p, -1)):  # b2 ~ p-1
        if not check_cell(i, j, a1, b1, a2, b2):
            return False

    return True


def main(a1, b1, a2, b2):
    # somosomo
    if T[a1][b1] != T[a2][b2]:
        return "no"

    # tate, yoko, tate
    for p in range(H + 2):
        if check_p1(p, a1, b1, a2, b2):
            return "yes"

    # yoko, tate, yoko
    for p in range(W + 2):
        if check_p2(p, a1, b1, a2, b2):
            return "yes"

    return "no"


if __name__ == '__main__':
    for a, b, A, B in Q:
        print(main(a, b, A, B))
