
N, K = [int(_) for _ in input().split()]
a = [int(_) for _ in input().split()]

s = sum(a[0:K])
ans = s
for i in range(K, N):
    s += a[i]
    s -= a[i-K]
    ans += s
print(ans)
