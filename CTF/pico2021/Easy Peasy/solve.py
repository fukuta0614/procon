from pwn import *
from hashlib import sha256
from binascii import hexlify, unhexlify
import sys

import gmpy
import Crypto.Util.number


if __name__ == '__main__':
    sock = remote("mercury.picoctf.net", 58913)

    ret = sock.recvline()  # 改行までを受けとる、改行が送られないとここで止まるので注意
    log.info(ret)

    while True:
        ret = sock.recvline().decode()
        log.info(ret)
        if "!" in ret:
            break

    ret = sock.recvline().decode()[:-1]
    log.info(ret)
    enc = ret

    ret = sock.recvuntil("encrypt? ").decode()
    log.info(ret)

    zeros = "0" * (50000-32)
    sock.sendline(zeros)

    ret = sock.recvuntil("Here ya go!\n").decode()
    log.info(ret)

    ret = sock.recvline().decode()[:-1]
    # log.info(ret)

    zeros = "0" * (32)
    sock.sendline(zeros)

    ret = sock.recvuntil("Here ya go!\n").decode()
    log.info(ret)

    ret = sock.recvline().decode()[:-1]
    # log.info(ret)
    result = ret

    print(len(enc), len(result))

    flag_enc =  [int(enc[2*i:2*(i+1)], 16) for i in range(len(enc)//2)]

    keys = [ord('0') ^ int(result[2*i:2*(i+1)], 16) for i in range(len(result)//2)]

    ans = "".join([chr(c ^ k) for c, k in zip(flag_enc, keys)])
    print(ans)

    sock.interactive()


