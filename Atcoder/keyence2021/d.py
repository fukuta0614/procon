
from itertools import combinations
from itertools import product
import bisect
import math

test = [0] * 8

for x in combinations(range(7), 3):
    for e in x:
        test[e] += 1


print(test)