N, S, T = [int(_) for _ in input().split()]
W = int(input())
A = [int(input()) for i in range(N-1)]

weight = W
count = 1 if S <= weight <= T else 0
for a in A:
    weight += a
    if S <= weight <= T:
        count += 1

print(count)

