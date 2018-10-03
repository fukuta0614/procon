from collections import defaultdict, OrderedDict

n, a, b = [int(x) for x in input().split()]

res = a+b-n

print(max(res, 0))