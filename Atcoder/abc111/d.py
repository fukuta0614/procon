from itertools import product

N = int(input())
P = [[int(_) for _ in input().split()] for i in range(N)]


def main():
    is_even = sum(P[0]) % 2 == 0

    for x, y in P[1:]:
        if ((x + y) % 2 == 0) != is_even:
            print(-1)
            return

    m = 31
    if is_even:
        arms = [1] + [2 ** n for n in range(m)]
    else:
        arms = reversed([2 ** n for n in range(m)])

    for x, y in P:
        tmp_x, tmp_y = x, y
        # if abs(x) > abs(y):




def func(mode, n, x, y):
    if mode == 0:
        x += n
    elif mode == 1:
        x -= n
    elif mode == 2:
        y += n
    else:
        y -= n
    return x, y


res1 = {}
for pro in product(range(4), repeat=6):
    x, y = 0, 0
    arms = [1, 1, 2, 4, 8, 16]
    for i in range(6):
        x, y = func(pro[i], arms[i], x, y)

    res1[(x, y)] = ''.join(['RLUD'[t] for t in pro])

import numpy as np
board = np.zeros((17, 17))
res2 = {}
m = 3
for pro in product(range(4), repeat=m):
    x, y = 0, 0
    arms = [1, 2, 4]
    for i in range(m):
        x, y = func(pro[i], arms[i], x, y)

    res2[(x, y)] = ''.join(['RLUD'[t] for t in pro])
    board[x+8][y+8] = 1

print(board)

if __name__ == '__main__':
    main()
