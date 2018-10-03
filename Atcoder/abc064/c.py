N = int(input())
A = [int(_) for _ in input().split()]


def color(n):
    if 1 <= n <= 399:
        return 0
    elif 400 <= n <= 799:
        return 1
    elif 800 <= n <= 1199:
        return 2
    elif 1200 <= n <= 1599:
        return 3
    elif 1600 <= n <= 1999:
        return 4
    elif 2000 <= n <= 2399:
        return 5
    elif 2400 <= n <= 2799:
        return 6
    elif 2800 <= n <= 3199:
        return 7
    else:
        return 8


x = [color(a) for a in A]
dora = x.count(8)
unique = len(set(x)) if dora == 0 else len(set(x)) - 1
min_ = max(1, unique)
max_ = unique + dora
print(min_, max_)
