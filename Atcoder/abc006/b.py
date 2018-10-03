
n = int(input())
mod = 10**4 + 7

if n == 1 or n == 2:
    print(0)
elif n == 3:
    print(1)
else:
    a, b, c = 0, 0, 1
    for i in range(n - 3):
        a, b, c = b, c, (a+b+c)%mod
    print(c % mod)