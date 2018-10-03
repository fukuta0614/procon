
N = int(input())
A = [0] + [int(a) for a in input().split()] + [0]
Q = int(input())
KX = [input().split() for _ in range(Q)]
K = [int(a[0]) for a in KX]
X = [int(a[1]) for a in KX]

