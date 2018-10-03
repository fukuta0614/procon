N = int(input())
a = [int(_) for _ in input().split()]

ans = -float('inf')
for i in range(N):
    tmp = (-1, -float('inf'), -float('inf'))
    p = -1
    for j in range(N):
        if j == i:
            continue
        elif j > i:
            taka = sum(a[i:j + 1:2])
            aoki = sum(a[i + 1:j + 1:2])
        else:
            taka = sum(a[j:i + 1:2])
            aoki = sum(a[j + 1:i + 1:2])

        if aoki > tmp[2]:
            tmp = (j, taka, aoki)
    j, taka, aoki = tmp
    ans = max(taka, ans)

print(ans)
