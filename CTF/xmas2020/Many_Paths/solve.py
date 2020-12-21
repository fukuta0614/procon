from pwn import *
from hashlib import sha256
from binascii import hexlify, unhexlify
import sys
import subprocess

import time

sys.setrecursionlimit(10000)

mod = 666013
def solve(N, adj, forbidden, L):

    edges = [[] for i in range(N)]
    for i in range(N):
        for j in range(N):
            if adj[i][j]:
                edges[i].append(j)

    dp = [[0] * N for i in range(L+1)]
    dp[0][0] = 1

    for l in range(L):
        for i in range(N):
            for j in edges[i]:
                dp[l+1][j] += dp[l][i]
                dp[l+1][j] %= mod

    return dp[L][N-1]


if __name__ == '__main__':
    p = remote("challs.xmas.htsp.ro", 6053)  # 127.0.0.1の12345ポートに接続する、processとAPIが同じなのでそっくりそのまま同じように動作する

    ret = p.recvline()  # 改行までを受けとる、改行が送られないとここで止まるので注意
    log.info(ret)

    for t in range(40):
        while True:
            ret = p.recvline()
            if "Test number" in ret.decode():
                break

        ret = p.recvline()
        N = int(ret.decode()[:-1].split("=")[1])

        ret = p.recvline()
        adj = []
        for i in range(N):
            ret = p.recvline()
            adj.append([int(x) for x in ret.decode()[:-1].split(",")])

        ret = p.recvline()
        tmp = ret.decode()[:-1].lstrip("forbidden nodes: [").rstrip("]").split(",")
        try:
            forbidden = [int(x) for x in tmp]
        except:
            forbidden = []

        ret = p.recvline()
        L = int(ret.decode()[:-1].split("=")[1])

        # print(N)
        # for i in range(N):
        #     print(adj[i])
        # print(forbidden)
        # print(L)
        log.info("{}: {} {} {}".format(t, N, L, len(forbidden)))

        with open("input.txt", "w") as f:
            f.write(str(N) + "\n")
            for i in range(N):
                for j in range(N):
                    f.write(str(adj[i][j]) + " ")
                f.write("\n")
            f.write(str(L))

        # ans = solve(N, adj, forbidden, L)
        with subprocess.Popen(["./solve"], stdout=subprocess.PIPE) as proc:
            ans = proc.stdout.read().decode()[:-1]
        p.sendline(ans)

        log.info("{}: {}".format(t, ans))

    p.interactive()
