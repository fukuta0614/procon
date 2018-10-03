
from collections import Counter
N = int(input())
A = [int(_) for _ in input().split()]

c = Counter(A)

for k in c:
    c[k] = 2 if c[k] % 2 == 0 else 1

two_count = len([x for x in list(c.values()) if x == 2])
all = len([x for x in list(c.values()) if x > 0])

res = all if two_count % 2 == 0 else all-1

print(res)
