
r, g, b = [int(_) for _ in input().split()]
n = 100*r + 10*g + b
print('YES' if n % 4 == 0 else 'NO')
