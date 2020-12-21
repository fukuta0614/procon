from pwn import *
from hashlib import sha256
from binascii import hexlify, unhexlify
import sys

import gmpy
import Crypto.Util.number

sys.setrecursionlimit(10000)


def solve_1(code):
    size = 5
    for n in range(16 ** 6):
        inp = "{:06x}".format(n)
        sh = sha256(unhexlify(inp)).hexdigest()[-size:]
        if sh == code:
            return inp


if __name__ == '__main__':
    p = remote("challs.xmas.htsp.ro", 1006)  # 127.0.0.1の12345ポートに接続する、processとAPIが同じなのでそっくりそのまま同じように動作する

    ret = p.recvline()  # 改行までを受けとる、改行が送られないとここで止まるので注意
    log.info(ret)

    code = ret.decode()[-6:-1]
    ans = solve_1(code)
    p.sendline(ans)

    while True:
        ret = p.recvline().decode()
        log.info(ret)
        if "n:" in ret:
            break
    n = int(ret.split(":")[1], 16)

    while True:
        ret = p.recvline().decode()
        log.info(ret)
        if "e:" in ret:
            break

    e = int(ret.split(":")[1], 16)

    for i in range(64):
        log.info(i)

        while True:
            ret = p.recvline().decode()
            log.info(ret)
            if "exit" in ret:
                break

        p.sendline("1")

        while True:
            ret = p.recvline().decode()
            log.info(ret)
            if "Let's sign something for you." in ret:
                break

        p.sendline(hex(i)[2:])
        while True:
            ret = p.recvline().decode()
            log.info(ret)
            if "Here's the signature: " in ret:
                break
        m = int(ret.split(":")[1], 16)
        print(i, (pow(m, e, n)))



    p.interactive()

    # p.recvuntil("exit")
    # p.sendline("1")
    #
    # p.recvuntil("message.\n")
    # msg = hexlify(bytes(16)).decode()
    # p.sendline(msg)
    #
    # ret = p.recvline()
    # print(ret)
    # h = ret.decode().lstrip("Here is your hash: b'").rstrip("'.\n")
    #
    # p.recvuntil("exit")
    # p.sendline("2")
    #
    # p.recvuntil("message.")
    # p.sendline(msg)
    #
    # p.recvuntil("message.")
    # print(h)
    # msg2 = hexlify(bytes(16) + unhexlify(h) + bytes(16)).decode()
    # p.sendline(msg2)
    #
    # p.interactive()
