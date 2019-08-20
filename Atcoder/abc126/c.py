
import math

N, K = [int(_) for _ in input().split()]


ans = 0
for i in range(1, N+1):

    if i >= K:
        ans += 1
    else:
        ans += 2 ** (-math.ceil(math.log2(K / i)))

print(ans / N)
