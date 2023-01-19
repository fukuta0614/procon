
N, A, B = [int(_) for _ in input().split()]

s1 = ''.join(['.' * B if i % 2 == 0 else '#' * B for i in range(N)])
s2 = ''.join(['#' * B if i % 2 == 0 else '.' * B for i in range(N)])

for i in range(N):
    for j in range(A):
        print(s1 if i % 2 == 0 else s2)

