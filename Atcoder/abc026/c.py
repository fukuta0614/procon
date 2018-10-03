N = int(input())
B = [int(input())-1 for i in range(N-1)]

tree = [[] for i in range(N)]

for i in range(N-1):
    tree[B[i]].append(i + 1)

def salary(n):
    if len(tree[n]) == 0:
        return 1

    min_ = float('inf')
    max_ = 0
    for s in tree[n]:
        x = salary(s)
        min_ = min(min_, x)
        max_ = max(max_, x)

    return max_ + min_ + 1

print(salary(0))