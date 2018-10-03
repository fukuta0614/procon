
pattern = 'WBWBWWBWBWBW'
re_pattern = 'WBWWBWBWBW'
s = input()
doremi = ['Do', 'Re', 'Mi', 'Fa', 'So', 'La', 'Si']

if s.startswith(re_pattern):
    print('Re')
    exit()

count = 0
for i in range(len(s)):
    if s[i:i + 12] == pattern:
        print(doremi[-count])
        break
    if s[i] == 'W':
        count += 1
