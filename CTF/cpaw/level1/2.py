
s = "fsdz{Fdhvdu_flskhu_lv_fodvvlfdo_flskhu}"

for offset in range(1, 26):

    tmp = ""
    for c in s:
        if c.islower():
            # print('lower', c, chr((ord(c) - ord('a') + offset) % 26 + ord('a')))
            tmp += chr((ord(c) - ord('a') + offset) % 26 + ord('a'))
        elif c.isupper():
            # print('upper', c, chr((ord(c) - ord('A') + offset) % 26 + ord('A')))
            tmp += chr((ord(c) - ord('A') + offset) % 26 + ord('A'))
        else:
            tmp += c
    print(tmp)