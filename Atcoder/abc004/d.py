R, G, B = [int(_) for _ in input().split()]


def func(N, left):
    if left <= -N:
        return (-left - left - N +1 ) * N // 2
    if 0 <= left:
        return (left + left + N - 1) * N // 2
    else:
        left = -left
        right = N - left - 1
        return left * (left + 1) // 2 + right * (right + 1) // 2

res = float('inf')
g_left = min(-G, 100 - B // 2 - G - 1)
g_right = max(0, -100 + R // 2 + 1)
for g in range(g_left, g_right+1):
    r = min(g - R, -100 - R // 2)
    b = max(g + G, 100 - B // 2)
    res = min(res, func(G, g) + func(R, 100+r) + func(B, -100+b))
print(res)
