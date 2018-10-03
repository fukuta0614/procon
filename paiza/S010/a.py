dice_info = [int(_) for _ in input().split()]
N = int(input())
P = [int(input()) for i in range(N)]

dice_map = {dice_info[i]: i for i in range(6)}

dice_table = [
    [0, 2, 1, 1, 1, 1],
    [2, 0, 1, 1, 1, 1],
    [1, 1, 0, 2, 1, 1],
    [1, 1, 2, 0, 1, 1],
    [1, 1, 1, 1, 0, 2],
    [1, 1, 1, 1, 2, 0],
]

ans = 0
up = dice_map[P[0]]
for i in range(1, len(P)):
    next_up = dice_map[P[i]]
    ans += dice_table[up][next_up]
    up = next_up

print(ans)
