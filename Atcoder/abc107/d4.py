N = int(input())
a_list = list(map(int, input().split()))

"""
python3 でも通ってるやつ
"""
import numpy as np

# N = 10 ** 5
# a_list = np.load("testcase.npy")
import time
start = time.time()

def search(c):
    bar = N
    r = 0
    res_nega = 0
    dp_arr = [0] * (2 * N + 1)
    for i in range(N):
        dp_arr[bar] += 1
        if a_list[i] < c:
            r += dp_arr[bar]
            bar += 1
        else:
            r -= (dp_arr[bar - 1])
            bar -= 1
        print(dp_arr, r, bar)
        res_nega += r
    return res_nega


# binary search
a_sorted = sorted(a_list)
C = N * (N + 1) // 2
inf = 0
sup = N
print(a_list)
while sup - inf > 1:
    mid = (sup + inf) // 2
    x = a_sorted[mid]
    print(x)
    if search(x) <= C // 2:
        inf = mid
    else:
        sup = mid

print(a_sorted[inf])
print(time.time() - start)
