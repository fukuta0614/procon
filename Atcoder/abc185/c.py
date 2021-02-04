
def nCk(n,  k):
    denominator = 1
    numerator = 1
    for i in range(k):
       numerator *= (n - i)
       denominator *= (i + 1)
    ret = numerator // denominator
    return ret

L = int(input())

ans = nCk(L-1, 11)
print(ans)

