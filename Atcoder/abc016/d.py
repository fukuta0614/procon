Ax, Ay, Bx, By = [int(_) for _ in input().split()]
N = int(input())
T = [[int(_) for _ in input().split()] for i in range(N)]
T += [T[0]]

c = (Bx - Ax, By - Ay)

def cross(a, b):
    return a[0] * b[1] - a[1] * b[0]

count = 0
for i in range(N):
    ax, ay = T[i]
    bx, by = T[i + 1]

    aA = (ax - Ax, ay - Ay)
    aB = (ax - Bx, ay - By)
    bA = (bx - Ax, by - Ay)
    bB = (bx - Bx, by - By)

    if cross(c,aA)*cross(c,bA) < 0 and  cross(aA, bA)  * cross(aB, bB) < 0:
        count += 1

print(count//2 + 1)
