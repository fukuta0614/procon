

N = int(input())
s = input()

x = 0
for i in range(N):
    if s[i] == 'R':
        x += 1

if 2 * x > N:
    print("Yes")
else:
    print("No")