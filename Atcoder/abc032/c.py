
def main1():
    N, K = [int(_) for _ in input().split()]
    s = [int(input()) for _ in range(N)]

    if 0 in s:
        print(len(s))
        exit()

    if K == 0:
        print(0)
        exit()

    S = []
    i = 0
    while i < len(s):
        if s[i] == 1:
            tmp = [1]
            while i < len(s)-1:
                if s[i+1] == 1:
                    tmp.append(1)
                    i += 1
                else:
                    break
            S.append(tuple(tmp))
        else:
            S.append(s[i])

        i += 1

    ans = 0
    for i in range(len(S)):
        r = i
        tmp = 1
        res = 0
        while r < len(S):
            if isinstance(S[r], tuple):
                res += len(S[r])
            else:
                tmp *= S[r]
                if tmp > K:
                    break
                else:
                    res += 1
            r += 1
        ans = max(ans, res)
    print(ans)

def main2():
    N, K = [int(_) for _ in input().split()]
    s = [int(input()) for _ in range(N)]

    if 0 in s:
        print(len(s))
        exit()

    ans = 0
    l = 0
    pr = 1
    for r in range(len(s)):
        pr *= s[r]
        if pr > K:
            pr //= s[l]
            l += 1
        else:
            ans += 1

    print(ans)

def main3():
    N, K = [int(_) for _ in input().split()]
    s = [int(input()) for _ in range(N)]

    if 0 in s:
        print(len(s))
        exit()
    pr = 1
    l = 0
    ans = 0
    for r in range(len(s)):
        pr *= s[r]
        while pr > K and l <= r:
            pr //= s[l]
            l += 1

        ans = max(ans, r - l + 1)
    print(ans)

