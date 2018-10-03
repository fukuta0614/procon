import math

N, A, B = [int(_) for _ in input().split()]
H = sorted([int(input()) for _ in range(N)])

sup = sum([h // A + 1 for h in H])
inf = 1

while sup - inf > 1:
    x = (sup + inf) // 2
    c = sum([math.ceil((h - x * B)/(A-B)) for h in H if h > x * B])
    if c <= x:
        sup = x
    else:
        inf = x

print(sup)





