s = input() + ' '

i = 0
x = ''
ans = ''
while i < len(s)-1:
    x = s[i]
    count = 1
    while s[i+1] == x and i < len(s):
        i += 1
        count += 1
    ans += x + str(count)
    i += 1
print(ans)