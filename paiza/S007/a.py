import re
import numpy as np

alphabets = "abcdefghijklmnopqrstuvwxyz"

S = input()
s_list = re.findall(r'([0-9]*)', S)

idx = 0
first = True
for s in S:
    if s in alphabets + "()":
        s_list[idx] = s
        idx += 1
        first = True
    elif first:
        first = False
        idx += 1

mul = []
mul_tmp = 1
ans = {c: 0 for c in alphabets}

idx = 0
while True:
    s = s_list[idx]
    if s in alphabets:
        ans[s] += np.prod(mul)
    elif s == ")":
        mul.pop()
    else:
        mul_tmp = int(s)
        idx += 1
        s = s_list[idx]
        if s == "(":
            mul.append(mul_tmp)
        else:
            ans[s] += mul_tmp * np.prod(mul)
    idx += 1

    if idx == len(s_list) - 1:
        break

for c in alphabets:
    print(c, int(ans[c]))
