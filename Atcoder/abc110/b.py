
N, M, X, Y = [int(_) for _ in input().split()]
x = [int(_) for _ in input().split()]
y = [int(_) for _ in input().split()]

if max(max(x), X) < min(min(y), Y):
    print("No War")
else:
    print("War")