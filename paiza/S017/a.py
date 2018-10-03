from itertools import combinations
from itertools import product
import bisect
import math

import numpy as np

N, M, S = [int(_) for _ in input().split()]
table = np.zeros((N + 2, N + 2)).astype("int32")
T = [[0 if x == "." else int(x) for x in input()] for i in range(N)]
table[1:N + 1, 1:N + 1] = T
print(table)

directions = [(-1, -1), (-1, 0), (-1, 1),
              (0, -1), (0, 0), (0, 1),
              (1, -1), (1, 0), (1, 1)]

candidates = []
conditions = []


def search_upleft(s, i, j):
    up = None
    left = None

    yoko_count = 1
    while True:
        next_cell = [i][j + yoko_count]
        if next_cell == s:
            yoko_count += 1
            if yoko_count == M:
                left = j
                break
        elif next_cell == 0:
            left = j - yoko_count
            break
        else:
            conditions.append((s, next_cell)) # s < next_cell
            break

    for yoko in range(M):
        if table[i-1][j + yoko] == 0:
            up = i

        tate_count = 1
        while True:
            next_cell = table[i + tate_count][j + p]
            if next_cell == s:
                tate_count += 1
                if tate_count == M:
                    up = i
                    break
            elif next_cell == 0:
                up = i - tate_count
                break
            else:
                conditions.append((s, next_cell))  # s < next_cell
                break


def main():
    for s in range(1, S + 1):
        for i in range(N):
            for j in range(N):
                if table[i][j] == s:
                    search_upleft(s, i, j)


if __name__ == '__main__':
    main()
