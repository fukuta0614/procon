
N = int(input())

print((N // 11) * 2 + (2 if N % 11 > 6 else 1 if N % 11 > 0 else 0))