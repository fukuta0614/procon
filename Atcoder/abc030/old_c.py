import bisect


def main():
    N, M = [int(_) for _ in input().split()]
    X, Y = [int(_) for _ in input().split()]
    a = [int(_) for _ in input().split()]
    b = [int(_) for _ in input().split()]

    t, n, m = 0, 0, 0
    ans = 0
    while True:
        while True:
            if n >= N:
                return ans
            if t <= a[n]:
                t = a[n] + X
                n += 1
                break
            else:
                n += 1

        while True:
            if m >= M:
                return ans
            if t <= b[m]:
                t = b[m] + Y
                m += 1
                break
            else:
                m += 1
        ans += 1

import bisect
def main2():
    N, M = [int(_) for _ in input().split()]
    X, Y = [int(_) for _ in input().split()]
    a = [int(_) for _ in input().split()]
    b = [int(_) for _ in input().split()]

    t, n, m = 0, 0, 0
    ans = 0
    while True:
        n = bisect.bisect_left(a, t)
        if n >= N:
            return ans
        t = a[n] + X

        m = bisect.bisect_left(b, t)
        if m >= M:
            return ans
        t = b[m] + Y

        ans += 1

print(main2())
