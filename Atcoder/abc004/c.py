N = int(input()) % 30

res = list(range(1, 6 + 1))

for i in range(N):
    res[i % 5], res[i % 5 + 1] = res[i % 5 + 1], res[i % 5 + 0]

print(''.join([str(_) for _ in res]))
