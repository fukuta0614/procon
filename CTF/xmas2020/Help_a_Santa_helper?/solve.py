from pwn import *
from hashlib import sha256
from binascii import hexlify, unhexlify
import sys

sys.setrecursionlimit(10000)


def solve_1(code):
    size = 5
    for n in range(16 ** 6):
        inp = "{:06x}".format(n)
        sh = sha256(unhexlify(inp)).hexdigest()[-size:]
        if sh == code:
            return inp


if __name__ == '__main__':
    p = remote("challs.xmas.htsp.ro", 1004)  # 127.0.0.1の12345ポートに接続する、processとAPIが同じなのでそっくりそのまま同じように動作する

    ret = p.recvline()  # 改行までを受けとる、改行が送られないとここで止まるので注意
    log.info(ret)

    code = ret.decode()[-6:-1]
    ans = solve_1(code)
    p.sendline(ans)
    log.info(ans)

    p.recvuntil("exit")
    p.sendline("1")

    p.recvuntil("message.\n")
    msg = hexlify(bytes(16)).decode()
    p.sendline(msg)

    ret = p.recvline()
    print(ret)
    h = ret.decode().lstrip("Here is your hash: b'").rstrip("'.\n")

    p.recvuntil("exit")
    p.sendline("2")

    p.recvuntil("message.")
    p.sendline(msg)

    p.recvuntil("message.")
    print(h)
    msg2 = hexlify(bytes(16) + unhexlify(h) + bytes(16)).decode()
    p.sendline(msg2)

    p.interactive()
