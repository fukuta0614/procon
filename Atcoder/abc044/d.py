
import math

n = int(input())
s = int(input())

def f(b, n):
    if n < b:
        return n
    else:
        return f(b, n//b) + n%b

if n == s:
    print(n+1)
    exit()

for b in range(2, int(math.sqrt(n))+1):
    if f(b, n) == s:
        print(b)
        exit()

for p in list(range(1, min(int(math.sqrt(n))+1, s+1)))[::-1]:
    q = s - p
    b = (n - q) // p
    if b >= 2 and f(b, n) == s:
        print(b)
        exit()

print(-1)