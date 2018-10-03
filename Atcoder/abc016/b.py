A, B, C = [int(_) for _ in input().split()]

if C == A + B:
    if C == A - B:
        print('?')
    else:
        print("+")
else:
    if C == A - B:
        print('-')
    else:
        print('!')