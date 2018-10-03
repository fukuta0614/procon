
from itertools import product

N, K = [int(_) for _ in input().split()]
D = set([int(_) for _ in input().split()])
valid = list(set(range(10)) - D)

x = set()
for r in range(1,6):
    for p in product(valid, repeat=r):
        x.add(int(''.join([str(i) for i in p])))

for n in sorted(x):
    if n >= N:
        print(n)
        break