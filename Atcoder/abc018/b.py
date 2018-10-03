s = input()
N = int(input())
T = [[int(_)-1 for _ in input().split()] for i in range(N)]

for l, r in T:
    s = s[:l] + s[l:r+1][::-1] + s[r+1:]
print(s)