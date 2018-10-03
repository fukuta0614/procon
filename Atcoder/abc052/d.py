
N, A, B = [int(_) for _ in input().split()]
X = [int(_) for _ in input().split()]
diff = [X[i] - X[i-1] for i in range(1, N)]

ans = 0
for x in diff:
    ans += min(A*x, B)
print(ans)
