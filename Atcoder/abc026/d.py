import math

A, B, C = [int(_) for _ in input().split()]

def f(t):
    return A*t + B*math.sin(C*t*math.pi)

d = - A / (B * C * math.pi)
if d < -1:
    inf = 0
    sup = (100+B)/A
elif d > 1:
    print(-1)
else:
    x = (math.acos(d) - math.pi) / (C * math.pi)
    while True:
        if f(x) < 100 and f(x+1/C) > 100:
            inf = x
            sup = x + 1/C
            break
        else:
            x += 1/C

t = (inf+sup)/2
while abs(f(t) - 100) > 1e-6:
    if f(t) > 100:
        sup = t
    else:
        inf = t
    t = (inf + sup) / 2

print(t)
