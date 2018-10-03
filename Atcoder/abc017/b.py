s = input()

i = 0
while i < len(s):
    if s[i] in 'oku':
        i += 1
        continue
    if s[i] == 'c' and i < len(s)-1:
        if s[i+1] == 'h':
            i += 2
            continue
    print('NO')
    break

else:
    print('YES')