
N = int(input())
S = input()

num = 0
ans = 0
for s in S:
    if s == 'I':
        num += 1
    else:
        num -= 1
    ans = max(ans, num)

print(ans)