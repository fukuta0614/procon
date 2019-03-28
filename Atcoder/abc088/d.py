
N = int(input())
A = [int(x) for x in input().split()]

r = 0
ref = 0
ans = 0
for l in range(N):
    while r < N and ref & A[r] == 0:
        ref ^= A[r]
        r += 1

    ans += r - l

    if r == l:
        r += 1
    else:
        ref ^= A[l]

print(ans)