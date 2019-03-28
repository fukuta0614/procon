N, A, B, C = [int(_) for _ in input().split()]
L = [int(input()) for i in range(N)]

max_loop_count = 4 ** N
K = [0, A, B, C]


def func(count):
    comb = [0] * N
    i = 0
    while count > 0:
        comb[i] = count % 4
        i += 1
        count //= 4

    tmp = 0
    for k in range(1, 4):
        num = 0
        sum_ = 0
        for i in range(N):
            if comb[i] == k:
                num += 1
                sum_ += L[i]

        if num == 0:
            return 3100

        tmp += 10 * (num - 1) + abs(sum_ - K[k])

    return tmp


ans = 3100
for lp in range(max_loop_count):
    ans = min(ans, func(lp))

print(ans)
