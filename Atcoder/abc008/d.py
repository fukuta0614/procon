def main_gomi():
    W, H = [int(_) for _ in input().split()]
    N = int(input())
    M = [[int(_) for _ in input().split()] for i in range(N)]

    sort_type = [lambda x: x[0], lambda x: x[1], lambda x: -x[0], lambda x: -x[1]]
    ans = 0
    for c in range(4):
        sum = 0
        m = sorted(M, key=sort_type[c])
        gold = [[not (j == 0 or j == W + 1 or i == 0 or i == H + 1) for j in range(W + 2)] for i in range(H + 2)]

        for y, x in m:
            gold[x][y] = False
            for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                num = 0
                while gold[x + (num + 1) * dx][y + (num + 1) * dy]:
                    gold[x + (num + 1) * dx][y + (num + 1) * dy] = False
                    # for g in gold:
                    #     print(' '.join(['$' if sd else '.' for sd in g]))
                    # print()
                    num += 1
                sum += num
        # print(sum)
        ans = max(sum, ans)

    print(ans + N)


W, H = [int(_) for _ in input().split()]
N = int(input())
M = [[int(_) for _ in input().split()] for i in range(N)]

memo = dict()

def dp(left, top, right, bottom):
    if (left, top, right, bottom) in memo:
        return memo[(left, top, right, bottom)]
    else:
        res = 0
        for i in range(N):
            if left <= M[i][0] <= right and top <= M[i][1] <= bottom:
                g = right - left + bottom - top + 1
                g += dp(left, top, M[i][0] - 1, M[i][1] - 1)
                g += dp(M[i][0] + 1, top, right, M[i][1] - 1)
                g += dp(left, M[i][1] + 1, M[i][0] - 1, bottom)
                g += dp(M[i][0] + 1, M[i][1] + 1, right, bottom)
                res = max(res, g)
        memo[(left, top, right, bottom)] = res
        return res

print(dp(1, 1, W, H))