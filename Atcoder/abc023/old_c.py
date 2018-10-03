R, C, K = [int(_) for _ in input().split()]
N = int(input())
T = [[int(_) - 1 for _ in input().split()] for i in range(N)]

row = [0] * R
col = [0] * C
for r, c in T:
    row[r] += 1
    col[c] += 1

row_count = [0] * (K + 1)
col_count = [0] * (K + 1)


for r in row:
    if r <= K:
        row_count[r] += 1
for c in col:
    if c <= K:
        col_count[c] += 1
count = 0
for k in range(K + 1):
    count += row_count[k]*col_count[K - k]

for r, c in T:
    if row[r] + col[c] == K:
        count -= 1
    elif row[r] + col[c] == K + 1:
        count += 1
print(count)