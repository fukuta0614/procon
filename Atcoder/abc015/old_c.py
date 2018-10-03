from functools import reduce

N, K = [int(_) for _ in input().split()]
T = [[int(_) for _ in input().split()] for i in range(N)]


def ten2num(n, K, digit):
    s = [0] * digit

    for i in range(digit):
        s[-i - 1] = str(n % K)
        n //= K
    return ''.join(s)


for n in range(K ** N):
    if reduce(lambda x, y: x ^ y, [T[i][int(m)] for i, m in enumerate(ten2num(n, K, N))]) == 0:
        print('Found')
        break
else:
    print('Nothing')
