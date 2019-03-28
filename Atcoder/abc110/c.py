S = input()
T = input()


def main():
    StoT = {}
    TtoS = {}

    for i in range(len(S)):

        if S[i] in StoT:
            if StoT[S[i]] != T[i]:
                print("No")
                return

        else:
            StoT[S[i]] = T[i]

            if T[i] in TtoS:
                if TtoS[T[i]] != S[i]:
                    print("No")
                    return
            else:
                TtoS[T[i]] = S[i]

    print("Yes")


if __name__ == '__main__':
    main()
