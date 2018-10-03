n, m = [int(_) for _ in input().split()]
n = n - 12 if n > 12 else n

M = 360 * m / 60
N = 360 * n / 12 + 30 * m / 60
print(min(abs(M-N), abs(360+M-N), abs(-360+M-N)))