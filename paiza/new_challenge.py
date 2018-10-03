import sys, os
dirname = sys.argv[1]
os.mkdir(dirname)

content = '''
from itertools import combinations
from itertools import product
import bisect
import math

N = int(input())
N, K = [int(_) for _ in input().split()]
T = [[int(_) for _ in input().split()] for i in range(N)]
'''
with open(os.path.join(dirname, 'a.py'), 'w') as f:
    f.write(content)
with open(os.path.join(dirname, 'arg.txt'), 'w') as f:
    f.write('')