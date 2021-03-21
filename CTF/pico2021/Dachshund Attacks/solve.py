from typing import Iterator, Iterable, Optional, Tuple, List


def rational_to_contfrac(x: int, y: int) -> Iterator[int]:
    while y:
        a = x // y
        yield a
        x, y = y, x - a * y


def contfrac_to_rational_iter(contfrac: Iterable[int]) -> Iterator[Tuple[int, int]]:
    n0, d0 = 0, 1
    n1, d1 = 1, 0
    for q in contfrac:
        n = q * n1 + n0
        d = q * d1 + d0
        yield n, d
        n0, d0 = n1, d1
        n1, d1 = n, d


def contfrac_to_rational(contfrac: List[int]) -> Tuple[int, int]:
    from functools import reduce
    return reduce(
        lambda f, q: (q * f[0] + f[1], f[0]),
        reversed(contfrac),
        (1, 0),
    )


def convergents_from_contfrac_naive(contfrac: List[int]) -> Iterator[Tuple[int, int]]:
    m = len(contfrac)
    for i in range(m):
        if i % 2 == 0:
            q = contfrac[:i + 1]
            q[i] += 1
            yield contfrac_to_rational(q)
        else:
            q = contfrac[:i + 1]
            yield contfrac_to_rational(q)


def convergents_from_contfrac(contfrac: Iterable[int]) -> Iterator[Tuple[int, int]]:
    n_, d_ = 1, 0
    for i, (n, d) in enumerate(contfrac_to_rational_iter(contfrac)):
        if i % 2 == 0:
            yield n + n_, d + d_
        else:
            yield n, d
        n_, d_ = n, d


def isqrt(n: int) -> int:
    if n == 0:
        return 0

    x = 2 ** ((n.bit_length() + 1) // 2)
    while True:
        y = (x + n // x) // 2
        if y >= x:
            return x
        x = y


def is_perfect_square(n: int) -> bool:
    sq_mod256 = (
    1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0)
    if sq_mod256[n & 0xff] == 0:
        return False

    mt = (
        (9, (1, 1, 0, 0, 1, 0, 0, 1, 0)),
        (5, (1, 1, 0, 0, 1)),
        (7, (1, 1, 1, 0, 1, 0, 0)),
        (13, (1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1)),
        (17, (1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1))
    )
    a = n % (9 * 5 * 7 * 13 * 17)
    if any(t[a % m] == 0 for m, t in mt):
        return False

    return isqrt(n) ** 2 == n


def attack(e: int, n: int) -> Optional[int]:
    f_ = rational_to_contfrac(e, n)
    for k, dg in convergents_from_contfrac(f_):
        edg = e * dg
        phi = edg // k

        x = n - phi + 1
        if x % 2 == 0 and is_perfect_square((x // 2) ** 2 - n):
            g = edg - phi * k
            return dg // g
    return None


import codecs


if __name__ == '__main__':

    e = 74935069661481708333187985249236738166951548441764503265912821531957500015482537586215202843526368726868171974911594368503816085977784979466097102086278475569039498626074868277800162110052728643924792009846504182162385075398030200681071964855636609630736730092566087935467989331353781486567189806270144385439
    n = 121958691662432307592378681323575530054751169508329619015418473551263629524147807149589973799779313160156444660441177455233088543434548801348775312344902907469218730835103323349127152818091685783710818908013595549340411672250695854095924179296889929626351564858712419891062931292102695879184615907447718913829
    c = 112339271383838874628045458465497657388538699263689895695223749129781331369408273669107585553534558613872870627298530106025175676141764134635698967949367182510186133776785864763836999395909111213422606086055204703988777672671495168544346569123585316017583920239755470685913660214302023300799706333935678977378

    d = attack(e, n)

    m = pow(c, d, n)
    print(codecs.decode("%0512x" % m, 'hex').decode())
