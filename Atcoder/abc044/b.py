
from collections import Counter

w = input()
c = Counter(w)
for k, v in c.items():
    if v % 2 != 0:
        print("No")
        exit()

print("Yes")
