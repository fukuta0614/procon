s = input()
letter = set(s)

for x in letter:
    tmp1 = ''
    tmp2 = ''
    for i in range(len(s)):
        if s[i] == tmp1:
            print(i, i+1)
            exit()
        elif s[i] == tmp2:
            print(i-1, i+1)
            exit()
        else:
            tmp2 = tmp1
            tmp1 = s[i]
else:
    print(-1, -1)
