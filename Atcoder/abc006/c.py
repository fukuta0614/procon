N, M = [int(_) for _ in input().split()]

for n in range(N+1):
    m = 4 * N - M - 2 * n
    if 0 <= m <= N - n:
        print(n, m, N-n-m)
        break
else:
    print(-1, -1, -1)
