R,C, K = [int(_) for _ in input().split()]
T = [[_ for _ in input()] for i in range(R)]

lr = [[None]*C for i in range(R)]

for x in range(R):
    for y in range(C):
        if T[x][y] == 'x':
            lr[x][y] = (0,0)
        else:
            l, r = K, K
            for i in range(1, min(K, C-y)):
                if T[x][y+i] == 'x':
                    r = i
                    break
            for i in range(1, min(K, y+1)):
                if T[x][y-i] == 'x':
                    l = i
                    break
            lr[x][y] = (l, r)

count = 0
for x in range(K-1, R-K+1):
    for y in range(K-1, C-K+1):

        for i in range(K):
            if lr[x+i][y][0] < K - i or lr[x+i][y][1] < K - i or lr[x-i][y][0] < K - i or lr[x-i][y][1] < K - i:
                break
        else:
            count += 1

print(count)