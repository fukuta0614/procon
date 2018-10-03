import math

xa, ya, xb, yb, xc, yc = [int(_) for _ in input().split()]

S = ((xb-xa) * (yc-ya) - (yb-ya) * (xc-xa)) / 2
print(math.fabs(S))
