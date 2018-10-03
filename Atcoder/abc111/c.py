from collections import Counter

n = int(input())
V = [int(_) for _ in input().split()]

A = V[::2]
B = V[1::2]

resA = Counter(A).most_common()
resB = Counter(B).most_common()

if resA[0][0] == resB[0][0]:
    ans1 = sum([num for x, num in resA[1:]]) + resB[0][1] + sum([num for x, num in resB[2:]])
    ans2 = sum([num for x, num in resB[1:]]) + resA[0][1] + sum([num for x, num in resA[2:]])
    print(min(ans1, ans2))
else:
    print(sum([num for x, num in resA[1:]]) + sum([num for x, num in resB[1:]]))
