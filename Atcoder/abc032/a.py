
from itertools import combinations
from itertools import product
import bisect
import math

a = int(input())
b = int(input())
n = int(input())

def euclidean_algorithm(m,n):
    if m % n == 0:
        return n
    else:
        return euclidean_algorithm(n,m%n)

i = 1
gcd = euclidean_algorithm(a,b)
lcm = (a * b // gcd)
while True:
    if i * lcm >= n:
        print(i * lcm)
        exit()
    else:
        i += 1
