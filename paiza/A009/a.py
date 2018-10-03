import numpy as np

H, W = [int(_) for _ in input().split()]
char_to_num = {s: i for i, s in enumerate("_/\\")}
box = np.array([[char_to_num[x] for x in list(input())] for i in range(H)])

direction_change = [
    # - / \
    [0, 2, 3],  # r,
    [1, 3, 2],  # l,
    [2, 0, 1],  # u,
    [3, 1, 0],  # d,
]

change_pos = [
    [0, 1],  # r
    [0, -1],  # l
    [-1, 0],  # u
    [1, 0],  # d
]

direction = 0  # r, l, u, d
pos = np.array([0, 0]).astype('int32')
ans = 0
while True:
    mirror = box[pos[0], pos[1]]
    direction = direction_change[direction][mirror]
    pos += change_pos[direction]
    ans += 1
    if not (0 <= pos[0] <= H - 1 and 0 <= pos[1] <= W - 1):
        break

print(ans)