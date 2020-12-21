from pwn import *
import pickle
import sys

import random


def middle_point(x1, y1, x2, y2):
    return (x1 + x2) / 2, (y1 + y2) / 2


def solve(pos, enemy):
    ans = []
    k = 10
    for i in range(-k, k + 1):
        for j in range(-k, k + 1):
            if abs(i) % 2 == 1:
                y = i + 1 - pos[1]
            else:
                y = i + pos[1]

            if abs(j) % 2 == 1:
                x = j + 1 - pos[0]
            else:
                x = j + pos[0]

            mx_tmp, my_tmp = middle_point(enemy[0], enemy[1], x, y)

            if abs(math.floor(my_tmp)) % 2 == 1:
                my = 1 - (my_tmp % 1)
            else:
                my = (my_tmp % 1)

            if abs(math.floor(mx_tmp)) % 2 == 1:
                mx = 1 - (mx_tmp % 1)
            else:
                mx = (mx_tmp % 1)

            # print(i, j, x, y, mx_tmp, my_tmp, mx, my, )
            ans.append((mx, my))

    final = []
    valid = [True] * len(ans)
    for i in range(len(ans)):
        if not valid[i]:
            continue
        final.append(ans[i])
        for j in range(i + 1, len(ans)):
            if abs(ans[i][0] - ans[j][0]) < 1e-8 and abs(ans[i][1] - ans[j][1]) < 1e-8:
                valid[j] = False

    return final


if __name__ == '__main__':

    p = remote("challs.xmas.htsp.ro", 6005)

    while True:
        ret = p.recvline().decode()
        log.info(ret)
        if "Good luck!" in ret:
            break
    p.recvuntil("Send any input to start..")
    p.sendline("")

    for i in range(50):
        lines = []
        for i in range(3):
            ret = p.recvline().decode()
            log.info(ret)
            lines.append(ret)

        pos = [float(x) for x in lines[1].split(":")[1].split(",")]
        enemy = [float(x) for x in lines[2].split(":")[1].split(",")]
        print(pos, enemy)

        ans = solve(pos, enemy)
        for i in range(16):
            if i < len(ans):
                p.sendline("{:.8f},{:.8f}".format(ans[i][0], ans[i][1]))
            else:
                p.sendline("0.5,0.5")

    p.interactive()
