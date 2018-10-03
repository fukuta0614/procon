from functools import reduce

N, K = [int(_) for _ in input().split()]
R = sorted([int(_) for _ in input().split()])

print(reduce(lambda x, y: (x + y) / 2, [0] + R[-K:]))
