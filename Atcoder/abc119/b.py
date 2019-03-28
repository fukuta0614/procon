
N = int(input())
ans = 0
for i in range(N):
    x, y = input().split()
    ans += int(x) if y == 'JPY' else float(x) * 380000

print(ans)