
N = int(input())

res = 0
for i in range(1, N):
    res = max(res, i * (N-i))

print(res)