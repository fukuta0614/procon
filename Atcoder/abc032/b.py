s = input()
k = int(input())

if k > len(s):
    print(0)
    exit()

ans = set()
for i in range(len(s)-k+1):
    ans.add(s[i:i+k])

print(len(ans))

