N, M = [int(_) for _ in input().split()]
X = [int(_) for _ in input().split()]
X.sort()


def solve():
    if N >= M:
        print(0)
        return

    diff = []
    for i in range(1, M):
        diff.append(X[i] - X[i - 1])

    diff.sort(reverse=True)

    sum_ = sum(diff)
    r = sum(diff[:N - 1])
    print(sum_ - r)


if __name__ == '__main__':
    solve()
