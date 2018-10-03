N = int(input())
NG = [int(input()) for i in range(3)]

if N in NG:
    print('NO')
else:
    for i in range(100):
        if not N - 3 in NG:
            N -= 3
        elif not N - 2 in NG:
            N -= 2
        elif not N - 1 in NG:
            N -= 1
        else:
            print('NO')
            break
    else:
        if N <= 0:
            print('YES')
        else:
            print('NO')
