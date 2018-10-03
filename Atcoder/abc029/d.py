N = input()

res = 0
for i in range(len(N)):
    d = int(N[i])
    l = len(N) - i - 1
    if d > 1:
        res += d * 10**l * l // 10
        res += 10 ** l
    elif d == 1:
        res += 10**l * l // 10
        if i < len(N)-1:
            res += int(N[i+1:])+1
        else:
            res += 1
print(res)
