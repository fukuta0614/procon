import math
N = int(input())
A = [int(_) for _ in input().split()]

l = [a for a in A if a > 0]
print(math.ceil(sum(l)/len(l)))