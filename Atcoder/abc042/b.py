

N, L = [int(_) for _ in input().split()]
T = [input() for i in range(N)]

ans = ''.join(sorted(T))
print(ans)
