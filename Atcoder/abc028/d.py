N, K = [int(_) for _ in input().split()]

res = 0
res += (N-K)*(K-1)*6
res += (N-1)*3
res += 1
print(res / N**3)