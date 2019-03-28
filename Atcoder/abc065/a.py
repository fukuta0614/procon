
N = int(input())
towns = [[int(x) for x in input().split()] for _ in range(N)]

x_order = sorted(towns, key=lambda x:x[0])
y_order = sorted(towns, key=lambda x:x[1])

