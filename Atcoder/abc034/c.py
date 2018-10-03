import math
mod = 10**9 + 7
W, H = [int(_) for _ in input().split()]

n = W + H - 2
a = math.factorial(n) % mod
b = (math.factorial(W-1) * math.factorial(H-1)) % mod
b_ = pow(b, mod-2, mod)
print((a * b_) % mod)


