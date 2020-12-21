from pwn import *
from hashlib import sha256
from binascii import unhexlify
import pickle
import sys

import random
import gmpy

from Crypto.PublicKey import RSA
from Crypto.Util.number import inverse
from Crypto.Util.number import GCD
from Crypto.Util.number import long_to_bytes

sys.setrecursionlimit(10000)


# argv = sys.argv
#
# DEBUG = False
# BINARY = './vuln'
#
# context.binary = BINARY
# context.terminal = ['tmux', 'splitw', '-v']
#
# def attach_gdb():
#   gdb.attach(sh)
#
#
# if DEBUG:
#   context.log_level = 'debug'


def solve_1(code):
  size = 5
  for n in range(16 ** 6):
    inp = "{:06x}".format(n)
    sh = sha256(unhexlify(inp)).hexdigest()[-size:]
    if sh == code:
      return inp


def random_prime(bits):
    while True:
        n = random.getrandbits(bits)
        if gmpy.is_prime(n):
            return n

def chinese_remainder(pairs):
    N = 1
    for a, n in pairs:
        N *= n

    result = 0
    for a, n in pairs:
        m = N // n
        d, r, s = gmpy.gcdext(n, m)
        if d != 1:
            raise ValueError("Input not pairwise co-prime")
        result += a*s*m

    return result % N, N

def hastads_broadcast_attack(e, pairs):
    x, n = chinese_remainder(pairs)
    return gmpy.root(x, e)[0]


def gcd(m,n):
    if m % n == 0:
        return n
    else:
        return gcd(n,m%n)

if __name__ == '__main__':

    p = remote("challs.xmas.htsp.ro", 1000) # 127.0.0.1の12345ポートに接続する、processとAPIが同じなのでそっくりそのまま同じように動作する

    ret = p.recvline() # 改行までを受けとる、改行が送られないとここで止まるので注意
    log.info(ret)

    code = ret.decode()[-6:-1]
    ans = solve_1(code)
    p.sendline(ans)
    log.info(ans)

    ret = p.recvuntil("exit")
    e = 65537
    pairs = []

    for i in range(255):
        log.info(i)

        p.sendline("1")
        ret = p.recvuntil("exit")

        ret = ret.decode().lstrip("\n")
        lines = ret.split("\n")

        c = int(lines[0].lstrip("Here is the encrypted secret message: ")[:-1], 16)
        n = int(lines[2].lstrip("n: "))

        pairs.append((c, n))

    with open("test.wb", "wb") as f:
        pickle.dump(pairs, f)

    m = 0
    for i in range(len(pairs)):
        for j in range(len(pairs)):
            if pairs[i][1] == pairs[j][1]:
                continue

            pp = gcd(pairs[i][1], pairs[j][1])
            if pp == 1:
                continue
            log.info("found!!!!")

            c, n = pairs[i]
            q = n // pp
            d = inverse(e, (pp - 1) * (q - 1))
            # key = RSA.construct(map(int, (n, e, d)))
            # m = key.decrypt(pairs[i][0])
            # print(n, p, q, d, e)
            m = pow(c, d, n)
            log.info(hex(m)[2:])
            break
        else:
            continue
        break


    #
    # x = hastads_broadcast_attack(e, pairs)
    # print(x)

    p.sendline("2")
    p.recvline()
    p.sendline(hex(m)[2:])

    p.interactive()
