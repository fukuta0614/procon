import numpy as np

N, D = [int(_) for _ in input().split()]

N = 100
D = 5 ** 27

N = 3
D = 2


def hash_func(a, b, c):
    return a * (60 ** 2) + b * 60 + c


def main():
    d_divisor = [0, 0, 0]
    for i, divisor in enumerate([5, 3, 2]):
        d = D
        while d % divisor == 0:
            d = d // divisor
            d_divisor[i] += 1

    print(d_divisor)
    # if np.prod(d_divisor) != D:
    #     print(0)
    #     return

    d_idx = d_divisor[0] * 60 ** 2 + d_divisor[1] * 60 + d_divisor[2]
    dp = [[0] * (60 ** 3) for _ in range(N + 1)]

    print(d_idx)
    dp[0][hash_func(0, 0, 1)] = 1
    dp[0][hash_func(0, 1, 0)] = 1
    dp[0][hash_func(1, 0, 0)] = 1
    dp[0][hash_func(0, 0, 2)] = 1
    dp[0][hash_func(0, 1, 1)] = 1

    for i in range(N):
        for k in range(d_idx + 1):
            c = k % (60 * 60)
            res = k // (60 * 60)
            b = res % 60
            a = res // 60

            tmp = k  # 1
            dp[i + 1][tmp] = dp[i][k] / 6

            tmp = a * 60 ** 2 + b * 60 + (c + 1)  # 2
            dp[i + 1][tmp] += dp[i][k] / 6

            tmp = a * 60 ** 2 + (b + 1) * 60 + c  # 3
            dp[i + 1][tmp] += dp[i][k] / 6

            tmp = a * 60 ** 2 + b * 60 + (c + 2)  # 4
            dp[i + 1][tmp] += dp[i][k] / 6

            tmp = (a + 1) * 60 ** 2 + b * 60 + c  # 5
            dp[i + 1][tmp] += dp[i][k] / 6

            tmp = a * 60 ** 2 + (b + 1) * 60 + (c + 1)  # 6
            dp[i + 1][tmp] += dp[i][k] / 6

    ans = 0
    print(dp[-1])
    for k in range(d_idx + 1):
        c = k % (60 * 60)
        res = k // (60 * 60)
        b = res % 60
        a = res // 60
        if a >= d_divisor[0] and b >= d_divisor[1] and c >= d_divisor[2]:
            ans += dp[-1][k]

    print(ans)


if __name__ == '__main__':
    main()
