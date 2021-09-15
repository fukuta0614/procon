from pwn import *
from hashlib import sha256
from binascii import hexlify, unhexlify
import sys

import gmpy
import Crypto.Util.number

from fractions import Fraction
from gmpy2 import powmod
import binascii
from Crypto.Cipher import DES

def pad(msg):
    block_len = 8
    over = len(msg) % block_len
    pad = block_len - over
    return (msg + " " * pad).encode()

def double_decrypt(c2, k1, k2):
    cipher2 = DES.new(k2, DES.MODE_ECB)
    c1 = cipher2.decrypt(c2)
    cipher1 = DES.new(k1, DES.MODE_ECB)
    return binascii.hexlify(cipher1.decrypt(c1)).decode()

def main():
    sock = remote("mercury.picoctf.net", 29980)

    ret = sock.recvline().decode()
    log.info(ret)

    ret = sock.recvline().decode()
    log.info(ret)

    flag_enc_hex = ret[:-1]
    enc_flag = binascii.unhexlify(flag_enc_hex.encode())

    ret = sock.recvuntil("What data would you like to encrypt? ").decode()
    log.info(ret)

    s = "0" * 16
    sock.sendline(s)

    msg_hex = binascii.unhexlify(s).decode()

    ret = sock.recvline().decode()[:-1]
    enc_msg_hex = ret[:16]

    enc_msg = binascii.unhexlify(enc_msg_hex.encode())

    encs = dict()

    for i in range(1000000):
        k1 = pad("{:06d}".format(i))

        cipher1 = DES.new(k1, DES.MODE_ECB)
        enc_msg1 = cipher1.encrypt(msg_hex)

        encs[enc_msg1] = k1

    for i in range(1000000):
        k2 = pad("{:06d}".format(i))

        cipher2 = DES.new(k2, DES.MODE_ECB)
        msg2 = cipher2.decrypt(enc_msg)

        if msg2 in encs:
            k1 = encs[msg2]
            print(k1, k2)
            break

    res = double_decrypt(enc_flag, k1, k2)
    ans = binascii.unhexlify(res)
    print(ans)

    sock.interactive()


if __name__ == '__main__':
    main()
    # test()
    # test2()

# 128427457270547733597355637098835975117267122164056137176336062703756597689672499156754407301023011889147002926888341245570730661954978358148095158137489760779381140078954606141056124401667214883038900031535346933616046759007475242244619944796969508881146266177478922904749222363660504981561633160936830408857
# 62820230236171576737223883673464139961165821473376022756939512271969215239505783597572169102413502460531103606627695962896461222308400599533993738458720727023636639547680619847956492001132149595047959951627040973807063033648474026886473680353013566578031021766375035462971228645725755025887195401837161542084
