
T = [int(_) for _ in input().split()]

x = sorted(T)
if x[0] == 5 and x[1] == 5 and x[2] == 7:
    print("YES")
else:
    print("NO")