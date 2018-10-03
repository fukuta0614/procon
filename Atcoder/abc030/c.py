import bisect

N, M = [int(_) for _ in input().split()]
X, Y = [int(_) for _ in input().split()]
a = [int(_) for _ in input().split()]
b = [int(_) for _ in input().split()]

t = 0
count = 0
while True:
    i = bisect.bisect_left(a, t)
    if i >= len(a):
        break
    t = a[i] + X
    j = bisect.bisect_left(b, t)
    if j >= len(b):
        break
    t = b[j] + Y
    count += 1

print(count)