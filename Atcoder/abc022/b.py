N = int(input())
A = [int(input()) for i in range(N)]

visited = set()

count = 0
for a in A:
    if a in visited:
        count += 1
    else:
        visited.add(a)
print(count)