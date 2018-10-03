
s = input()

a = None
for i in range(len(s)):
    if a is None:
        if s[i] == 'A':
            a = i
    else:
        if s[i] == 'Z':
            z = i

print(z - a + 1)
