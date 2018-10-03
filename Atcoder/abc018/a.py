A = int(input())
B = int(input())
C = int(input())

l = [A, B, C]
l = sorted(l, reverse=True)
print(l.index(A)+1)
print(l.index(B)+1)
print(l.index(C)+1)
