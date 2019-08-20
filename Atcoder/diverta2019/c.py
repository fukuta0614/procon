
N = int(input())

tmp = [0,0,0]
ans = 0
for i in range(N):
    s = input()
    ans += s.count("AB")
    if s.endswith("A") and s.startswith("B"):
        tmp[0] += 1
    elif s.endswith("A"):
        tmp[1] += 1
    elif s.startswith("B"):
        tmp[2] += 1


if tmp[0] > 0:
    ans += tmp[0] - 1

    if tmp[1] > 0:
        ans += 1
        tmp[1] -= 1

    if tmp[2] > 0:
        ans += 1
        tmp[2] -= 1

ans += min(tmp[1], tmp[2])
print(ans)
