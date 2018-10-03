from collections import Counter

N = int(input())
s = [input() for i in range(N)]

print(Counter(s).most_common()[0][0])