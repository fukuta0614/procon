
A, B, C = [int(_) for _ in input().split()]

m = pow(B, C, 4)
x = A % 10

if m == 0:
    m = 4

ans = pow(x, m)
ans = ans % 10

print(ans)