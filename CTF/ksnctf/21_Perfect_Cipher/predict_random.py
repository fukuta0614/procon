import random
import struct

def untemper(x):
    x = unBitshiftRightXor(x, 18)
    x = unBitshiftLeftXor(x, 15, 0xefc60000)
    x = unBitshiftLeftXor(x, 7, 0x9d2c5680)
    x = unBitshiftRightXor(x, 11)
    return x

def unBitshiftRightXor(x, shift):
    i = 1
    y = x
    while i * shift < 32:
        z = y >> shift
        y = x ^ z
        i += 1
    return y

def unBitshiftLeftXor(x, shift, mask):
    i = 1
    y = x
    while i * shift < 32:
        z = y << shift
        y = x ^ (z & mask)
        i += 1
    return y

seq = []
with open('encrypt.key', 'rb') as f:
    data = f.read()
    for i in range(len(data)//4):
        n = struct.unpack('<I', data[4*i:4*i+4])[0]
        seq.append(n)


mt_state = tuple([untemper(x) for x in seq[-624:]] + [624])
random.setstate((3, mt_state, None))


with open("flag.key", "wb") as f:
    for i in range(19639):
        x = random.getrandbits(32)
        b = struct.pack('<I', x)
        f.write(b)
