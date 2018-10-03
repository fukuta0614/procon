N, A, B = [int(_) for _ in input().split()]
T = [input().split() for i in range(N)]

chokudai = 0

for s, d in T:
    d = min(max(int(d), A), B)
    chokudai += d if s == 'East' else -d

if chokudai == 0:
    print(0)
elif chokudai > 0:
    print('East', chokudai)
else:
    print('West', -chokudai)
