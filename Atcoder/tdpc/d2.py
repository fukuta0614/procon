from collections import defaultdict

N, D = [int(_) for _ in input().split()]


def main():
    d_divisor = [0, 0, 0]
    d = D
    for i, divisor in enumerate([5, 3, 2]):
        while d % divisor == 0:
            d = d // divisor
            d_divisor[i] += 1

    d5, d3, d2 = d_divisor

    if d != 1:
        print(0)
        return

    dp = defaultdict(float)
    dp[(0, 0, 0)] = 1

    for i in range(N):
        tmp = defaultdict(float)
        for k, v in dp.items():
            a, b, c = k

            tmp[(a, b, c)] += v / 6
            tmp[(a, b, min(d2, c + 1))] += v / 6
            tmp[(a, min(d3, b + 1), c)] += v / 6
            tmp[(a, b, min(d2, c + 2))] += v / 6
            tmp[(min(d5, a + 1), b, c)] += v / 6
            tmp[(a, min(d3, b + 1), min(d2, c + 1))] += v / 6

        dp = tmp

    print(dp[(d5, d3, d2)])


if __name__ == '__main__':
    main()
