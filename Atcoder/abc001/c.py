Deg, Dis = [int(_) for _ in input().split()]

Deg /= 10
direction = ['N', 'NNE', 'NE', 'ENE', 'E', 'ESE', 'SE', 'SSE', 'S', 'SSW', 'SW', 'WSW', 'W', 'WNW', 'NW', 'NNW']

d = 11.25
for i in range(1, 16):
    if d <= Deg < d + 22.5:
        Dir = direction[i]
        break
    else:
        d += 22.5
else:
    Dir = direction[0]


def my_round(x, d):
    p = 10 ** d
    return (x * p * 2 + 1) // 2 / p


Dis = my_round(Dis / 60, 1)
wind_length = [0.2, 1.5, 3.3, 5.4, 7.9, 10.7, 13.8, 17.1, 20.7, 24.4, 28.4, 32.6]

for i in range(12):
    if Dis <= wind_length[i]:
        W = i
        break
else:
    W = 12

if W == 0:
    print('C', W)
else:
    print(Dir, W)
