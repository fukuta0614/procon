H, W, A, B = map(int, input().split())
ans = 0
def dfs(i, bit, A, B):
    if i == H * W:
        global ans
        ans += 1
        return
    if bit >> i & 1:
        dfs(i + 1, bit, A, B)
        return
    if B:
        dfs(i + 1, bit | 1 << i, A, B - 1)
    if A:
        if i % W != W - 1 and not bit & 1 << (i + 1):
            dfs(i + 1, bit | 1 << i | 1 << (i + 1), A - 1, B)
        if i + W < H * W:
            dfs(i + 1, bit | 1 << i | 1 << (i + W), A - 1, B)
dfs(0, 0, A, B)
print(ans)