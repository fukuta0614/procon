s = input()

ans = []
for i in range(len(s)):
    if s[i] == '0':
        ans.append('0')
    elif s[i] == '1':
        ans.append('1')
    elif s[i] == 'B' and not len(ans) == 0:
        ans.pop()
print(''.join(ans))