
N = int(input())
T = [list(input()) for i in range(N)]

for i in range(N):
    for j in range(N):
        print(T[N-j-1][i], end='')
    print()

