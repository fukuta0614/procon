
from itertools import permutations, combinations

n = int(input())
S = [int(_) for _ in input().split()]
m = int(input())
P = [[int(_) for _ in input().split()] for i in range(m)]


def is_smaller(A, B):
    for i in range(len(A)):
        if A[i] < B[i]:
            return True
        elif A[i] > B[i]:
            return False
    else:
        return True


ans = S[:]
for num in range(1, m+1):
    for pattern in permutations(range(m), num):
        T = S[:]
        for idx in pattern:
            tmp = T[:]
            for i in range(n):
                T[P[idx][i]-1] = tmp[i]

        if is_smaller(T, ans):
            ans = T[:]

print(*ans)