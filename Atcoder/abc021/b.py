N = int(input())
a, b = [int(_) for _ in input().split()]
K = int(input())
P = [int(_) for _ in input().split()]

P = [a] + P + [b]

if len(set(P)) == len(P):
    print("YES")
else:
    print("NO")