N = int(input())
s = [int(input()) for _ in range(N)]

S = sum(s)
if S % 10 != 0:
    print(S)
else:
    num = [n for n in s if n % 10 != 0]
    if len(num) == 0:
        print(0)
    else:
        print(S - min(num))
