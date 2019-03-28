
K, A, B = [int(_) for _ in input().split()]

def main():
    if B - A <= 2:
        print(K + 1)
        return

    if K < A + 1:
        print(K + 1)
        return

    ans = B
    k = K - (A + 1)

    ans += (k // 2) * (B - A) + (k % 2)

    print(ans)


if __name__ == '__main__':
    main()
