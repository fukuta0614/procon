A = int(input())
B = int(input())
C = int(input())

mod = 10 ** 9 + 7
d = pow(B * C - (B + C) * A, mod - 2, mod)

r = ((A - B) * C) * d % mod
c = ((A - C) * B) * d % mod

print(r, c)