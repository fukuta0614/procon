
N, K = [int(_) for _ in input().split()]
A = [int(_)-1 for _ in input().split()]
S = [input() for _ in range(N)]

res = [S[i] for i in A]

cnt = 0

max_query = min(res, key=lambda x: len(x))

inf = -1
sup = len(max_query) + 1

while sup - inf > 1:
    med = (inf + sup) // 2

    flag = True
    for i in range(N):
        if i in A:
            if not S[i].startswith(max_query[:med]):
                flag = False
                break
        else:
            if S[i].startswith(max_query[:med]):
                flag = False
                break

    if flag:
        sup = med
    else:
        inf = med

if sup == len(max_query) + 1:
    print(-1)
else:
    print(max_query[:sup])



