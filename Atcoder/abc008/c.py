def main():
    from itertools import permutations

    N = int(input())
    c = [int(input()) for i in range(N)]

    res = 0
    count = 0
    for order in permutations(range(N)):

        count += 1
        c_ = [c[order[i]] for i in range(N)]
        L = [1] * N
        for i in range(N):
            for j in range(i + 1, N):
                if c_[j] % c_[i] == 0:
                    L[j] *= -1
        res += sum([1 if l > 0 else 0 for l in L])

    print(res / count)


def main2():

    N = int(input())
    c = [int(input()) for i in range(N)]

    res = 0
    for i in range(N):
        n = c[i]
        divider = 0
        for j in range(N):
            if j == i:
                continue
            if n % c[j] == 0:
                divider += 1
        if (divider+1) % 2 == 0:
            res += 1/2
        else:
            res += (divider+2) / 2 / (divider + 1)

    print(res)

main2()