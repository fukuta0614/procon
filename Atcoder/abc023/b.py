N = int(input())
S = input()

res = ['b']
for i in range(1, N+1):
    if i % 3 == 1:
        res.append('a' + res[-1] + 'c')
    if i % 3 == 2:
        res.append('c' + res[-1] + 'a')
    if i % 3 == 0:
        res.append('b' + res[-1] + 'b')

if S in res:
    print(res.index(S))
else:
    print('-1')