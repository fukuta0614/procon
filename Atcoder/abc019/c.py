N = int(input())
a = [int(_) for _ in input().split()]

ans = set()
for n in a:
    while n % 2 == 0:
        n //= 2
    ans.add(n)
print(len(ans))