A,B,C,D = [int(_) for _ in input().split()]

if B/A > D/C:
    print("TAKAHASHI")
elif B * C == D * A:
    print("DRAW")
else:
    print("AOKI")