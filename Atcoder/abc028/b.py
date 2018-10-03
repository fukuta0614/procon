S = input()

d = {x:i for i, x in enumerate("ABCDEF")}
ans = [0] * 6
for s in S:
    ans[d[s]] += 1
print(' '.join([str(x) for x in ans]))


