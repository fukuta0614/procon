from pwn import *
from hashlib import sha256
from binascii import hexlify, unhexlify
import sys

import gmpy
import Crypto.Util.number

from fractions import Fraction
from gmpy2 import powmod


def lsb_decryption_oracle(e, n, c, oracle):
    l, r = 0, Fraction(n, 1) # [l, r)
    i = 1
    while r - l >= 1:
        print(i, l, r)
        m = Fraction(l + r, 2)
        if oracle(powmod(2, i * e, n) * c % n):
            l = m
        else:
            r = m
        i += 1
    return math.ceil(l)


def test():
    n = 0x00c1e6ad543efcdd3cc8e6cafa580cd3b875a96a8bfdf87e207cddd333f120bce34fc1e1c7893f69065370d47d63c5e52bd342ad34f9b6d326a76c77cf21b6a299953825042f1a57a4886df800a868f5e301725b6ff957382f100375bef368250908192b3be2015d6284eb07cc492321452a74f664d2fe317c2651e306d69e5a7d0fb88bad26878b7bc82b836e5a23f336c3a30ad161c5769e4429ef6ac6803f217b015de4c1251fac8f92f1bafa5fa36573a0dddb8b5b1a5c39ff162c8aaca32a7a3fa872d3565b781cca4dc3e0e095d884c97032e4e3f3f3a31788d110b1d9ab60e39c6ad6742d9460be8432fe33a6b506473acaef8badb88ab74a3fa79bfa61
    e = 65537

    def decrypt_lsb(c):
        d = 0x00c087fe7f7273be71c6c273b5948c580606bf0c0ea9457e675fd51b0bae57e576881169d0a9550f41bac48419656270a5cd859d5ac6c1647433361ed8cb0efff1241bb595abf7aa22b35d0e2e090aff6c42597cb5788dc439e6daa8a5cc2712ef1edd6ef26cfd11eeeb303c73fa0329dbf5c66189c77fa33f350586399a0d6ea698e9b59b7a6434672e247d96c0d5a6f70d8bd403c9b59e4c25cf9208f3a56920837d817ca3dde1f456c7b5a568f1f4802777a58e93308a94826c9a1e19bfce23c715937b7a47d4200150f2af0e5163e130ecdd0ad89062c7356cb5b3a3dc0b9f2de73b1f40bcc93b40b31ba1e46055336d782826e4955242bb0b23a4a5e90001
        m = pow(c, d, n)
        return m % 2

    m = 1234567890123456789012345678901234567890
    c = pow(m, e, n)

    print(lsb_decryption_oracle(e, n, c, decrypt_lsb))


def test2():
    n = 0x00c1e6ad543efcdd3cc8e6cafa580cd3b875a96a8bfdf87e207cddd333f120bce34fc1e1c7893f69065370d47d63c5e52bd342ad34f9b6d326a76c77cf21b6a299953825042f1a57a4886df800a868f5e301725b6ff957382f100375bef368250908192b3be2015d6284eb07cc492321452a74f664d2fe317c2651e306d69e5a7d0fb88bad26878b7bc82b836e5a23f336c3a30ad161c5769e4429ef6ac6803f217b015de4c1251fac8f92f1bafa5fa36573a0dddb8b5b1a5c39ff162c8aaca32a7a3fa872d3565b781cca4dc3e0e095d884c97032e4e3f3f3a31788d110b1d9ab60e39c6ad6742d9460be8432fe33a6b506473acaef8badb88ab74a3fa79bfa61
    e = 65537

    def decrypt_lsb(c):
        d = 0x00c087fe7f7273be71c6c273b5948c580606bf0c0ea9457e675fd51b0bae57e576881169d0a9550f41bac48419656270a5cd859d5ac6c1647433361ed8cb0efff1241bb595abf7aa22b35d0e2e090aff6c42597cb5788dc439e6daa8a5cc2712ef1edd6ef26cfd11eeeb303c73fa0329dbf5c66189c77fa33f350586399a0d6ea698e9b59b7a6434672e247d96c0d5a6f70d8bd403c9b59e4c25cf9208f3a56920837d817ca3dde1f456c7b5a568f1f4802777a58e93308a94826c9a1e19bfce23c715937b7a47d4200150f2af0e5163e130ecdd0ad89062c7356cb5b3a3dc0b9f2de73b1f40bcc93b40b31ba1e46055336d782826e4955242bb0b23a4a5e90001
        m = pow(c, d, n)
        return m

    m = 1234567890123456789012345678901234567890
    c = pow(m, e, n)

    x = pow(2, e, n) * c % n
    m_tmp = decrypt_lsb(x)
    if m_tmp % 2 == 0:
        print('even', m_tmp // 2)
    else:
        print('ood', (m_tmp + n) // 2)


def main():
    sock = remote("mercury.picoctf.net", 2671)

    ret = sock.recvline()  # 改行までを受けとる、改行が送られないとここで止まるので注意
    log.info(ret)

    while True:
        ret = sock.recvline().decode()
        log.info(ret)
        if "n:" in ret:
            break

    n = int(ret[3:])

    while True:
        ret = sock.recvline().decode()
        log.info(ret)
        if "e:" in ret:
            break

    e = int(ret[3:])

    while True:
        ret = sock.recvline().decode()
        log.info(ret)
        if "ciphertext: " in ret:
            break

    c = int(ret[len("ciphertext: "):])

    def decrypt_lsb(c):
        ret = sock.recvuntil("Give me ciphertext to decrypt: ").decode()

        sock.sendline(str(c))

        ret = sock.recvuntil("Here you go: ").decode()
        ret = sock.recvline().decode()

        m = int(ret)
        return m

    print(n, e, c)

    x = pow(2, e, n) * c % n
    m_tmp = decrypt_lsb(x)
    if m_tmp % 2 == 0:
        m = m_tmp // 2
        print('even')
    else:
        m =  (m_tmp + n) // 2
        print('ood')

    print(m)
    # ans = lsb_decryption_oracle(e, n, c, decrypt_lsb)
    # print(ans)

    sock.interactive()


if __name__ == '__main__':
    main()
    # test()
    # test2()

# 128427457270547733597355637098835975117267122164056137176336062703756597689672499156754407301023011889147002926888341245570730661954978358148095158137489760779381140078954606141056124401667214883038900031535346933616046759007475242244619944796969508881146266177478922904749222363660504981561633160936830408857
# 62820230236171576737223883673464139961165821473376022756939512271969215239505783597572169102413502460531103606627695962896461222308400599533993738458720727023636639547680619847956492001132149595047959951627040973807063033648474026886473680353013566578031021766375035462971228645725755025887195401837161542084
