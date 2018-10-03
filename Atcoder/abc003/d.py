import math

R, C = [int(_) for _ in input().split()]
X, Y = [int(_) for _ in input().split()]
D, L = [int(_) for _ in input().split()]

mod = 10 ** 9 + 7

c_box = (R - X + 1) * (C - Y + 1)

space = X * Y - D - L
x = []


def func(c):
    if c < 0:
        return 0
    a = math.factorial(D + L + c) % mod
    b = (math.factorial(D) * math.factorial(L) * math.factorial(c)) % mod
    b_ = pow(b, mod - 2, mod)
    return (a * b_) % mod


if space > 0:
    ans = func(space)
    ans -= 2 * func(space - X) + 2 * func(space - Y)
    ans += 4 * func(space - X - Y + 1) + func(space - 2 * Y) + func(space - 2 * X)
    ans -= 2 * func(space - 2 * X - Y + 2) + 2 * func(space - 2 * Y - X + 2)
    ans += func(space - 2 * X - 2 * Y + 4)
else:
    ans = func(0)
print((c_box * ans) % mod)
