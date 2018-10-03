N = int(input())
T = [[int(_) for _ in input().split()] for i in range(N)]


def valid(x):

    limit = [0] * N
    for h, s in T:
        t = (x - h) // s
        t = int((x-h)/s)
        if t < 0:
            return False
        if t < N:
            limit[t] += 1

    cum = 0
    for i in range(N):
        cum += limit[i]
        if cum > i+1:
            return False
    else:
        return True

inf = 0
sup = 10**15
while sup - inf > 1:
    med = (inf+sup) // 2

    if valid(med):
        sup = med
    else:
        inf = med

print(sup)