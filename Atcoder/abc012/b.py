N = int(input())
h = N // 3600
m = (N % 3600) // 60
s = N % 60

print('{:02d}:{:02d}:{:02d}'.format(h,m,s))