import sys

N = int(input())

max_dist = 0
x = 0
for i in range(2, N+1):
    print("? {0} {1}".format(1, i))
    sys.stdout.flush()
    dist = int(input())
    if dist > max_dist:
        x = i
        max_dist = dist

max_dist = 0
y = 0
for i in range(1, N+1):
    if i == x:
        continue
    print("? {0} {1}".format(x, i))
    sys.stdout.flush()
    dist = int(input())
    if dist > max_dist:
        y = i
        max_dist = dist

print("! {}".format(max_dist))