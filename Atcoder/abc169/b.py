


N = int(input())
A = [int(_) for _ in input().split()]

if 0 in A:
    print(0)
    exit(0)

ans = 1
for i in range(N):
    ans *= A[i]
    if ans > 1e18:
        print(-1)
        exit(0)

print(ans)