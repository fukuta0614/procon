

T = int(input())

for t in range(T):

    S = input()
    N = [int(x) for x in S]
    ans = ""
    r = 0
    for n in N:
        if n >= r:
            ans += '(' * (n-r)
            ans += str(n)
            r = n
        else:
            ans += ')' * (r-n)
            ans += str(n)
            r = n
    else:
        ans += ')' * r
    print("case #{}: {}".format(t+1, ans))



