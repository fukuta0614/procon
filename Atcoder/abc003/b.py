S = input()
T = input()

atcoder = ['a','t','c','o','d','e','r']

for i in range(len(S)):
    if S[i] == T[i]:
        continue
    elif S[i] == '@' and T[i] in atcoder:
        continue
    elif T[i] == '@' and S[i] in atcoder:
        continue
    elif T[i] == '@' and S[i] == '@':
        continue
    else:
        print('You will lose')
        break
else:
    print('You can win')