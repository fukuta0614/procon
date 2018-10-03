n = int(input())
a = [int(_) for _ in input().split()]

count = 0
for i in a:
    while i % 2 == 0 or i % 3 == 2:
        i -= 1
        count += 1
print(count)