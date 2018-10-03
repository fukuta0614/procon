

N, M = [int(_) for _ in input().split()]
A = [list(input()) for i in range(N)]
B = [list(input()) for i in range(M)]

for i in range(N-M+1):
    for j in range(N-M+1):
        flag = True
        for k in range(M):
            for l in range(M):
                if A[i+k][j+l] != B[k][l]:
                    flag = False
                    break
            if not flag:
                break
        if flag:
            print('Yes')
            exit()

print('No')