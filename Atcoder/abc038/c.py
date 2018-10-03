
N = int(input())
a = [int(_) for _ in input().split()]

l = 0
ans = 0
for i in range(1, N):
    if a[i] > a[i-1]:
        ans += i-l
    else:
        l = i
print(ans + N)