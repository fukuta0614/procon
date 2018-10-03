N = int(input())
a = [int(_) for _ in input().split()]

if sum(a) % N > 0:
    print(-1)
    exit()

mean = sum(a) // N
i = 0
ans = 0

while i < N:
    tmp = a[i]
    n = 1
    while tmp != mean * n:
        i += 1
        n += 1
        tmp += a[i]
    ans += n-1
    i += 1
print(ans)
