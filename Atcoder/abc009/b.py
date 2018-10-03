N = int(input())
A = [int(input()) for i in range(N)]

print(sorted(set(A))[-2])