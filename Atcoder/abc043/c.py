
N = int(input())
a = [int(_) for _ in input().split()]

ans = float('inf')
for n in range(-100, 101):
    ans = min(ans, sum([(n-x)**2 for x in a]))

print(ans)