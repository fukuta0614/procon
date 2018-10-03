H, W, N = [int(_) for _ in input().split()]
T = [[int(_) for _ in input().split()] for i in range(N)]

field = [[0] * W for _ in range(H)]


def set_u(h, w, left):
    up = None
    for y in range(H):
        for x in range(left, left + w):
            if field[y][x] == 1:
                up = y - h
                return up

    if up is None:
        return H - h


def main():
    for block in T:
        h, w, left = block

        up = set_u(h, w, left)

        for i in range(up, up + h):
            for j in range(left, left + w):
                field[i][j] = 1

    for i in range(H):
        print("".join(["#" if v else "." for v in field[i]]))


if __name__ == '__main__':
    main()
