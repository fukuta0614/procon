from pwn import *
from hashlib import sha256
from binascii import hexlify, unhexlify
import sys
import subprocess
import numpy as np
import time

sys.setrecursionlimit(10000)

def solve(N, K, P, Q, v):

    sub = np.array([P] * K + [Q] * (N-K))
    sub.sort()

    v = np.array(v)
    ans = 0
    while True:
        v.sort()
        if v[-1] <= 0:
            break
        v -= sub
        ans += 1

    return ans


def valid(x, N, K, P, Q, v):

    if P < Q:
        base = P
        diff = Q - P
        k = N-K
    else:
        base = Q
        diff = P - Q
        k = K

    v = np.array(v).copy()
    v -= base * x
    v = v[v > 0]

    need = (v + diff - 1) // diff
    return need.max() <= x and need.sum() <= x * k

    # for i in range(N):
    #     n = (v[i] + diff - 1) // diff
    #     if n > x:
    #         return False
    #     num += n
    #
    # return num <= x * k


def solve2(N, K, P, Q, v):

    mn = min(P, Q)
    ok = (max(v) + mn - 1) // mn
    ng = 0

    while ok - ng > 1:

        mid = (ok + ng) // 2

        if valid(mid, N, K, P, Q, v):
            ok = mid
        else:
            ng = mid

    return ok



if __name__ == '__main__':
    p = remote("challs.xmas.htsp.ro", 6055)  # 127.0.0.1の12345ポートに接続する、processとAPIが同じなのでそっくりそのまま同じように動作する

    ret = p.recvline()  # 改行までを受けとる、改行が送られないとここで止まるので注意
    log.info(ret)

    for t in range(100):
        while True:
            ret = p.recvline()
            # log.info(ret.decode())
            if "not the correct" in ret.decode():
                print(N, K, P, Q, v)
                exit()
            if "Test number" in ret.decode():
                break

        ret = p.recvline()
        a, b = ret.decode()[:-1].split(",")
        N = int(a.split("=")[1])
        K = int(b.split("=")[1])

        ret = p.recvline()
        a, b = ret.decode()[:-1].split(",")
        P = int(a.split("=")[1])
        Q = int(b.split("=")[1])

        ret = p.recvline()
        a, b, c, d = ret.decode()[:-1].split(",")
        v0 = int(a.split("=")[1])
        a = int(b.split("=")[1])
        c = int(c.split("=")[1])
        mod = int(d.split("=")[1])

        # v = [0] * N
        # v[0] = v0
        # for i in range(1, N):
        #     v[i] = (a * v[i-1] + c) % mod

        # log.info("{}: {} {} {} {} {} {} {} {}".format(t, N, K, P, Q, v0, a, c, mod))

        with open("input.txt", "w") as f:
            f.write("{} {} {} {} {} {} {} {}".format(N, K, P, Q, v0, a, c, mod)+ "\n")

        # ans = solve2(N, K, P, Q, v)
        # tmp = solve(N, K, P, Q, v)
        # print(ans, tmp)
        # p.sendline(str(ans))

        with subprocess.Popen(["./solve"], stdout=subprocess.PIPE) as proc:
            ans = proc.stdout.read().decode()[:-1]

        p.sendline(ans)

        log.info("{}: {}".format(t, ans))

    p.interactive()
