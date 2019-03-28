from itertools import product
import math

# D, G = [int(_) for _ in input().split()]
#
# P = [0] * D
# C = [0] * D
# for i in range(D):
#     P[i], C[i] = [int(_) for _ in input().split()]
#
# max_P = sum(P)


# V = []
# for i in range(D):
#     v = P[i] * (i + 1) * 100 + C[i]
#     V.append(v)
#
# def func(bit_pattern):
#     score = 0
#     tmp = 0
#     for i in range(D):
#         if bit_pattern[i]:
#             score += V[i]
#             tmp += P[i]
#
#     if score >= G:
#         return tmp
#
#     res = G - score
#
#     for i in reversed(range(D)):
#         if not bit_pattern[i]:
#             x = math.ceil(res / ((i + 1) * 100))
#             if x < P[i]:
#                 return tmp + x
#
#     return max_P
#
#
# ans = max_P
# for bit_pattern in product(range(2), repeat=10):
#     tmp = func(bit_pattern)
#     ans = min(ans, tmp)
#
# print(ans)


D, G = [int(_) for _ in input().split()]

P = [0] * D
C = [0] * D
for i in range(D):
    P[i], C[i] = [int(_) for _ in input().split()]
max_P = sum(P)

V = []
for i in range(D):
    V.append(((i + 1) * 100, i, False))
    v = (P[i] * (i + 1) * 100 + C[i]) / P[i]
    V.append((v, i, True))

V = sorted(V, key=lambda x: x[0], reverse=True)

def is_valid(x):
    used = [0] * D

    score = 0
    res = x
    for v, idx, need_comp in V:
        if used[idx] == 1:
            continue

        if need_comp:
            if P[idx] <= res:
                res -= P[idx]
                score += P[idx] * (idx + 1) * 100 + C[idx]
                used[idx] = 1

        else:
            score += res * (idx + 1) * 100
            break

    return score >= G


inf = 0
sup = max_P
while sup - inf > 1:
    mid = (inf + sup) // 2

    if is_valid(mid):
        sup = mid
    else:
        inf = mid

print(sup)
