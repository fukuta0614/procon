import math

N = int(input())
SE = [input().split('-') for i in range(N)]

ans = []


def time_round(t, type):
    if type == 'floor':
        m = math.floor(int(t[2:]) * 2 / 10) * 5
    else:
        m = math.ceil(int(t[2:]) * 2 / 10) * 5

    if m == 60:
        return '{:02d}00'.format(int(t[:2]) + 1)
    else:
        return t[:2] + '{:02d}'.format(m)


def time_round_2(t, type):
    if type == 'floor':
        return t - t % 5
    else:
        y = t + (5 - t % 5 if t % 5 else 0)
        y += (40 if y % 100 == 60 else 0)
        return y


for t in sorted(SE, key=lambda x: x[0]):
    start = time_round(t[0], 'floor')
    end = time_round(t[1], 'ceil')

    if len(ans) == 0:
        ans.append([start, end])
    elif int(end) <= int(ans[-1][1]):
        continue
    elif int(start) <= int(ans[-1][1]):
        ans[-1][1] = end
    else:
        ans.append([start, end])

for a in ans:
    print('-'.join(a))
