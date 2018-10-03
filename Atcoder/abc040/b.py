import math
n = int(input())

route_n = int(math.sqrt(n))

ans = float('inf')
for i in range(1, route_n+1):
    a, b = i, n//i
    ans = min(ans, n-a*b + b-a)

print(ans)



