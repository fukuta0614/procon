import math

N = int(input())
R = sorted([int(input()) for i in range(N)], reverse=True)

x = 1
ans = 0
for r in R:
    ans += x * r**2
    x *= -1

print(ans * math.pi)

