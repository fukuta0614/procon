L, H = [int(_) for _ in input().split()]
N = int(input())
for i in range(N):
    a = int(input())
    if a > H:
        print(-1)
    elif L <= a <= H:
        print(0)
    else:
        print(L-a)
