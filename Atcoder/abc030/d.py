N, a = [int(_) for _ in input().split()]
k = int(input())
b = [int(_) for _ in input().split()]

block = [a]
x = a
while True:
    x = b[x-1]
    if x in block:
        break
    else:
        block.append(x)

idx = block.index(x)
if k < idx:
    print(block[k])
else:
    print(block[idx + (k-idx) % (len(block)-idx)])

