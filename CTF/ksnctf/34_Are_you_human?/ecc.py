# coding: utf-8

# Add Reed-Solomon code
# usage: python ecc.py flag.jpg flag_ecc.jpg

import copy
import sys
import random

# finit field
# primitive polynomial: x^8+x^4+x^3+x^2+1=0
class GF:
    A = [1<<i for i in range(8)]
    for _ in range(8,255):
        a = A[-1]<<1
        if a>>8:
            a ^= 0b100011101
        A += [a]
    A += [0]
    Ai = [A.index(i) for i in range(256)]

    def __init__(s, v):
        assert not isinstance(v, GF)
        s.v = v.v if isinstance(v, GF) else v

    def __mul__(s, o):
        return GF(255) if 255 in (s.v, o.v) else GF((s.v+o.v)%255)

    def __add__(s, o):
        return GF(s.Ai[s.A[s.v]^s.A[o.v]])

    def __str__(s):
        return str(s.v)

    def __repr__(s):
        return "GF(%s)"%repr(s.v)

    def __eq__(s, o):
        return s.v==o.v

    def __ne__(s, o):
        return s.v!=o.v

    def inv(s):
        assert s.v!=255
        return GF((255-s.v)%255)

# polynomial
class Poly:
    def __init__(s, v):
        s.v = [x if isinstance(x,GF) else GF(x) for x in v]

    def __len__(s):
        return len(s.v)

    def __add__(s, o):
        return Poly([
            (s.v[i] if i<len(s) else GF(255)) +
            (o.v[i] if i<len(o) else GF(255))
            for i in range(max(len(s), len(o)))
        ])

    def __mul__(s, o):
        r = Poly([255]*(len(s)+len(o)-1))
        for i in range(len(o)):
            for j in range(len(s)):
                r.v[i+j] += o.v[i]*s.v[j]
        return r

    def shift(s, n):
        return Poly([255]*n+s.toarray())

    def __mod__(s, o):
        assert len(s)>=len(o)
        assert o.v[-1]==GF(0)
        t = copy.deepcopy(s)
        for i in range(len(s)-len(o)+1)[::-1]:
            t += (o * Poly([t.v[len(o)+i-1]])).shift(i)
        del t.v[len(o)-1:]
        return t

    def __str__(s):
        return "[" + ", ".join(str(x) for x in s.v) + "]"

    def __repr__(s):
        return "Poly([" + ", ".join(repr(x) for x in s.v) + "])"

    def apply(s, x):
        t = GF(0)
        r = GF(255)
        for i in range(len(s)):
            r += s.v[i]*t
            t *= x
        return r

    def toarray(s):
        return [x.v for x in s.v]

N = 255
K = 64

def ecc(data):
    assert len(data)==K

    I = Poly(map(ord, data))

    # G(x) = Π[0<=i<N-K](x+α^i)
    G = Poly([0])
    for i in range(N-K):
        G *= Poly([i, 0])

    # P(x) = x^(N-K) I(x) mod G(x)
    P = Poly([0]).shift(N-K) * I % G

    return "".join(map(chr, P.toarray()))

D = open(sys.argv[1], "rb").read()
D += "\x00"*((K-len(D))%K)

E = ""
for i in range(0,len(D),K):
    print "%d/%d"%(i,len(D))
    E += ecc(D[i:i+K])

# Add noise :)
FLAG = "FLAG_XXXXXXXXXXXXXXXX"
random.seed(FLAG)
T = map(ord, D+E)
for _ in range(len(T)/100):
    T[random.randint(0,len(T)-1)] = random.randint(0,255)
T = "".join(map(chr, T))

open(sys.argv[2], "wb").write(T)
