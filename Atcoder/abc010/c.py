import math

txa, tya, txb, tyb, T, V = [int(_) for _ in input().split()]
n = int(input())
xy = [[int(_) for _ in input().split()] for i in range(n)]

for x, y in xy:
    if T*V >= math.sqrt((x - txa) ** 2 + (y - tya) ** 2) + math.sqrt((txb - x) ** 2 + (tyb - y) ** 2):
        print('YES')
        break
else:
    print('NO')
