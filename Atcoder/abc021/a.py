N = int(input())

digits = []
while N > 0:
    digits.append(N % 2)
    N //= 2

print(len([d for d in digits if d > 0]))
for i, n in enumerate(digits):
    if n > 0:
        print(2**i)

