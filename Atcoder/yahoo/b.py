from collections import Counter

node = []
for i in range(3):
    node.extend([int(_) - 1 for _ in input().split()])


if Counter(node).most_common()[0][1] >= 3:
    print("NO")
else:
    print("YES")

