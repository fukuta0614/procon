R,C,K = [int(_) for _ in input().split()]
N = int(input())
T = [[int(_) for _ in input().split()] for i in range(N)]

row = [0]*R
col = [0]*C

for r,c in T:
    row[r] += 1
    col[c] += 1

count_row = [0]*(K+1)
count_col = [0]*(K+1)

for r in range(R):
    if row[r] <= K:
        count_row[row[r]] += 1

for c in range(C):
    if col[c] <= K:
        count_col[col[c]] += 1

ans = 0
for i in range(K):
    ans += count_row[i] * count_col[K-i]

for r, c in T:
    if row[r] + col[c] == K:
        ans -= 1
    if row[r] + col[c] == K + 1:
        ans += 1
print(ans)

