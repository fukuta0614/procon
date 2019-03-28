N, K = [int(_) for _ in input().split()]
A = [int(_) for _ in input().split()]


def solve():
    ans = 0
    bigable = True

    for i in range(41)[::-1]:

        tmp = 1 << i
        sum_ = 0
        for a in A:
            sum_ += (tmp & a > 0)

        # Kより大きい可能性があったら0確定
        if bigable and K & tmp == 0:
            ans += sum_ * tmp
            continue

        # 1のほうが多かったら、0を選択
        if sum_ >= N / 2:
            ans += sum_ * tmp
            if K & tmp > 0:
                bigable = False
        else:
            ans += (N - sum_) * tmp

    print(ans)


if __name__ == '__main__':
    solve()
