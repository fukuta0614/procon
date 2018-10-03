
N = int(input())
a = [int(input()) for _ in range(N)]

x = {s:i for i, s in enumerate(sorted(set(a)))}

for d in a:
    print(x[d])