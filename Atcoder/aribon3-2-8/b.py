
N = 500

def calc(x):
    cnt=0
    while x > 9:
        n = x
        tmp = 1
        while n > 0:
            tmp *= n % 10
            n //= 10
        x = tmp
        cnt += 1

    return cnt


p2 = [1]
for i in range(N):
    p2.append(p2[-1] * 2)

p3 = [1]
for i in range(N):
    p3.append(p3[-1] * 3)

p7 = [1]
for i in range(N):
    p7.append(p7[-1] * 7)


mx = 0
mx_cnt = 0
for i in range(N):
    print(i , '/',  N, mx_cnt, mx)
    for j in range(N):
        for k in range(N):
            x = p2[k] * p3[j] * p7[i]
            cnt = calc(x) + 1
            if cnt > mx_cnt:
                mx = '2' * k + '3' * j + '7' * i
                mx_cnt = cnt

