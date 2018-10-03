A, B, C = [int(_) for _ in input().split()]

if A >= B:
    if A >= C:
        print(A * 10 + B + C)
    else:
        print(C * 10 + B + A)
else:
    if B >= C:
        print(B * 10 + A + C)
    else:
        print(C * 10 + B + A)
