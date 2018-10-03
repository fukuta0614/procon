N = int(input())
T = [0] * 1000002
for i in range(N):
    a, b = [int(_) for _ in input().split()]
    T[a] += 1
    T[b+1] -= 1

for i in range(len(T)-1):
    T[i+1] += T[i]

print(max(T))