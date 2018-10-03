
S = input()
K = int(input())

for i in range(min(len(S), K)):
    s = S[i]
    if s != '1':
        print(s)
        break
else:
    print('1')
