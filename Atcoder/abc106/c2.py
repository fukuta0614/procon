
S = input()
K = int(input())

first_idx = -1
first_num = -1

for i in range(len(S)):
    s = S[i]
    if s != '1':
        first_idx = i + 1
        first_num = s
        break

if first_num == -1:
    print(S[0])
else:
    if K <= first_idx:
        print(1)
    else:
        print(first_num)

