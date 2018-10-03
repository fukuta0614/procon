from itertools import combinations
X = [int(_) for _ in input().split()]

ans = set()
for num in combinations(X, 3):
    ans.add(sum(num))

print(sorted(ans)[-3])
