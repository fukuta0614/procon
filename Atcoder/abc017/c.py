N, M = [int(_) for _ in input().split()]
T = [[int(_) for _ in input().split()] for i in range(N)]

imos = [0]*(M+2)
S = 0
for l, r, s in T:
    imos[l] += s
    imos[r+1] -= s
    S += s

for i in range(1, M+2):
    imos[i] += imos[i-1]

print(S - min(imos[1:M+1]))

