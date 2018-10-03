N, Q = [int(_) for _ in input().split()]
T = [[int(_)-1 for _ in input().split()] for i in range(Q)]

x = [0] * (N+1)
for l,r in T:
    x[l] += 1
    x[r+1] += -1

for i in range(1, N):
    x[i] += x[i-1]

print(''.join([str(a%2) for a in x[:N]]))
