def main():
    S = input()
    keyence = 'keyence'

    i = 0
    while True:
        if S[i] != keyence[i]:
            break

        if i == len(keyence) - 1:
            print("YES")
            return

        i += 1

    res = len(keyence) - i

    i = -res
    while True:
        if S[i] != keyence[i]:
            print("NO")
            return

        if i == -1:
            print("YES")
            return

        i += 1

if __name__ == '__main__':
    main()
