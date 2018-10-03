score = 0
for i in range(3):
    s, e = [int(_) for _ in input().split()]
    score += s * e * 0.1

print(int(score))