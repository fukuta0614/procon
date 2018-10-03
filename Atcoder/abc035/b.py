from collections import Counter
S = input()
T = int(input())

c = Counter(S)
lr = abs(c['L'] - c['R'])
ud = abs(c['U'] - c['D'])
hatena = c['?']
if T == 1:
    print(lr+ud+hatena)
else:
    if lr + ud >= hatena:
        print(lr + ud - hatena)
    else:
        x = hatena - (lr + ud)
        print(0 if x % 2 == 0 else 1)
