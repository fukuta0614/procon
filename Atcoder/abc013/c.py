import math

N, H = [int(_) for _ in input().split()]
A, B, C, D, E = [int(_) for _ in input().split()]

res = float('inf')
for X in range(N+1):
    Y = max(0, math.floor((E*(N-X) - (H+B*X)) / (E+D) + 1))
    Z = N - X - Y
    cost = A * X + C * Y
    hunger = H + B*X + D*Y - Z * E
    res = min(cost, res)
print(res)

