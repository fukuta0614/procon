
import numpy as np

N = int(input())
a = np.array([int(_) for _ in input().split()])

for i in np.argsort(-a):
    print(i+1)
