N, K = [int(_) for _ in input().split()]
S = list(input())
sorted_S = sorted(S)


res = []
for i in range(N):
    order = 0
    while True:
        T = res + [sorted_S[order]]
        remainder = S[:]
        for x in T:
            remainder.remove(x)

        k = 0
        for j in range(N):
            if j <= i:
                if S[j] != T[j]:
                    k += 1
            else:
                if S[j] in remainder:
                    remainder.remove(S[j])
                else:
                    k += 1

        if k > K:
            order += 1
        else:
            res.append(sorted_S.pop(order))
            break
print(''.join(res))