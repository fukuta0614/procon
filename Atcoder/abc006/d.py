import bisect

N = int(input())
T = [int(input()) for i in range(N)]

L = [0]

for i in range(N):
    if T[i] > L[-1]:
        L.append(T[i])
    else:
        j = bisect.bisect_left(L, T[i])
        L[j] = T[i]

print(N - len(L) + 1)