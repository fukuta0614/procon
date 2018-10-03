from itertools import product
N = int(input())
x = ['a','b','c']
for p in product(x, repeat=N):
    print(''.join(p))
