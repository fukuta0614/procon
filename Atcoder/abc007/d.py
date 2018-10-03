A, B = [int(_) for _ in input().split()]

def func(N):
    n = len(str(N))
    res = 0
    r = 0
    while r < n:
        head = int(str(N)[r])

        if head < 4:
            res += head * 8**(n-r-1)
        elif head == 4:
            res += 4 * 8 ** (n-r-1)
            break
        elif head < 9:
            res += (head-1) * 8**(n-r-1)
        elif head == 9:
            res += 8 * 8 ** (n-r-1)
            break

        r += 1
    return N - res + 1

print(func(B) - func(A-1))
