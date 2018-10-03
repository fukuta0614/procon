m = int(input())
m /= 1000

if m < 0.1:
    vv = '00'
elif m <= 5:
    vv = '{:02d}'.format(int(m*10))
elif m <= 30:
    vv = '{:02d}'.format(int(m) + 50)
elif m <= 70:
    vv = '{:02d}'.format(int((m-30)//5 + 80))
else:
    vv = '89'
print(vv)