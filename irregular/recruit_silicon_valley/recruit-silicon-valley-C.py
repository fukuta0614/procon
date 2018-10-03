import numpy as np
import time

# N = int(input())
# L = [int(input()) for i in range(N)]

N = 6
L = [4,9,7,6,20,1]


N = 15
L = [69,70,94,66,100,42,85,92,44,68,6,94,78,60,54]
N = 1000
L = list(np.random.randint(10000000,size=N))
def solve():
    ret = float("INF")

    LL = []
    for i in range(len(L)):
        LL.append(L[i:] + L[:i])
    # print(L)
    count = 0
    for li in range(N):
        l = LL[li]
        flag = False
        local_min = float("INF")

        for i in reversed(range(1, len(l) - li)):
            x = abs(sum(l[:i]) - sum(l[i:]))
            if local_min < x:
                # print("\n-> next\n")
                break
            local_min = min(local_min, x)
            ret = min(ret, x)
            count += 1
            if ret == 0:
                flag = True
                break
        if flag:
            break
    # print("loop count", count)
    print(ret)


def cycle_list(l,index):
    return l[index%len(l)]

def solve_fukuta():
    tmp_sum_list = list(L)
    whole_sum = sum(L) / 2.0
    sum_list = [0] * N
    tmp_min = float('inf')

    for num in range(1,N//2):
        
        for index in range(N):
            s = tmp_sum_list[index] + cycle_list(L,index+num)
            tmp_min = min(tmp_min,abs(whole_sum - s))
            sum_list[index] = s
        tmp_sum_list = list(sum_list)
        # print(sum_list)

    print(2 * tmp_min)

start = time.time()
solve()
t = time.time()
print(t - start)
solve_fukuta()
print(time.time()-t)

