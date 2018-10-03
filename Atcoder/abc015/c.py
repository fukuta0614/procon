from itertools import product
from functools import reduce

N, K = [int(_) for _ in input().split()]
T = [[int(_) for _ in input().split()] for i in range(N)]

for p in product(range(K), repeat=N):
    res = reduce(lambda x,y: x ^y, [T[i][p[i]] for i in range(N)])
    if res == 0:
        print('Found')
        break
else:
    print('Nothing')