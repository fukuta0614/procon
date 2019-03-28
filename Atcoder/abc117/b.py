
N = int(input())
L = [int(_) for _ in input().split()]

max_ = max(L)
sum_ = sum(L) - max_
if sum_ > max_:
    print("Yes")
else:
    print("No")


