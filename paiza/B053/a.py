
import numpy as np

H, W = [int(_) for _ in input().split()]
cells = [[int(_) for _ in input().split()] for i in range(2)]

table = np.zeros((H, W)).astype("int32")
table[:2, :2] = cells

diff = table[:, 1] - table[:, 0]
for j in range(2, W):
    table[:, j] = table[:, j-1] + diff


diff2 = table[1] - table[0]
for i in range(2, H):
    table[i] = table[i-1] + diff2

for row in table:
    print(*row)
