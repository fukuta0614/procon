S = input()
T = input()


def main():
    convert_table = {}
    for i in range(len(S)):
        if S[i] == T[i]:
            continue

        if S[i] in convert_table:
            if convert_table[S[i]] != T[i]:
                print("No")
                return
        else:
            convert_table[S[i]] = T[i]

    deletes = []
    for src in convert_table:
        dst = convert_table[src]
        if dst not in S:
            deletes.append(src)

    for src in deletes:
        del convert_table[src]

    while len(convert_table) > 0:
        start = list(convert_table)[0]
        visited = [start]
        s = start
        while True:
            t = convert_table[s]
            if t == start:
                break

            visited.append(t)
            if t in convert_table:
                s = t
            else:
                print("No")
                return

        for src in visited:
            del convert_table[src]

    print("Yes")


if __name__ == '__main__':
    main()
