N = int(input())

S = sum([i*j for i in range(1, 10) for j in range(1, 10)])
p = S - N
for i in range(1, 10):
    if p % i == 0 and p // i < 10:
        print('{} x {}'.format(i, p//i))