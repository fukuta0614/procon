N = int(input())
A = [int(_) for _ in input().split()]
B = [int(_) for _ in input().split()]

diff = [0] * N
minus_count = 0
minus_sum = 0
for i in range(N):
    diff[i] = A[i] - B[i]
    if diff[i] < 0:
        minus_count += 1
        minus_sum += -diff[i]

diff = sorted(diff, reverse=True)
cumsum = [0] * (N + 1)
for i in range(N):
    cumsum[i] += diff[i] + cumsum[i - 1]

# print(minus_count)
# print(minus_sum)
# print(diff)
# print(cumsum)


def check(x):
    a = x - minus_count
    if a < 0:
        return False

    plus_sum = cumsum[a - 1]
    # print(x, a)
    # print('plus', plus_sum)
    # print('minus', minus_sum)
    if plus_sum >= minus_sum:
        return True


def main():
    if sum(A) < sum(B):
        print(-1)
        return

    sup = N
    inf = -1
    while sup - inf > 1:
        mid = (sup + inf) // 2

        if check(mid):
            sup = mid
        else:
            inf = mid

    print(sup)


if __name__ == '__main__':
    main()
