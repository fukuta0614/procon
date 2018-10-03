n, X = [int(_) for _ in input().split()]
a = [int(_) for _ in input().split()]

ans = 0
for i in range(n):

    if X & 1:
        ans += a[i]
    X >>= 1
print(ans)