N = int(input())
S = input()
s = S[:]
while '()' in s:
    s = s.replace('()', '')
ans = '(' * s.count(')') + S + ')' * s.count('(')
print(ans)
