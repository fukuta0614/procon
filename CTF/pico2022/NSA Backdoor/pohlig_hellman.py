def egcd(m, n):
    if n > 0:
        y, x, d = egcd(n, m % n)
        return x, y - m / n * x, d
    else:
        return 1, 0, m


def modinv(a, m):
    (inv, q, gcd_val) = egcd(a, m)
    return inv % m


def chinese_remainder(Q, X):
    P = reduce(lambda x, y: x * y, Q)
    result = 0
    for i in xrange(len(X)):
        x, y, d = egcd(Q[i], P / Q[i])
        result += y * (P / Q[i]) * X[i]
    return result % P


# Baby-step giant-step
def baby_step_giant_step(g, y, p, q):
    m = int(q ** 0.5 + 1)

    # Baby-step
    baby = {}
    b = 1
    for j in xrange(m):
        baby[b] = j
        b = (b * g) % p

    # Giant-step
    gm = pow(modinv(g, p), m, p)
    giant = y
    for i in xrange(m):
        if giant in baby:
            x = i * m + baby[giant]
            print
            "Found:", x
            return x
        else:
            giant = (giant * gm) % p
    print
    "not found"
    return -1


# Pohlig-Hellman algorithm
def pohlig_hellman(p, g, y, phi_p):
    Q = map(int, phi_p.split(" * "))
    print
    "[+] Q:", Q
    X = []
    for q in Q:
        x = baby_step_giant_step(pow(g, (p - 1) / q, p), pow(y, (p - 1) / q, p), p, q)
        X.append(x)
    print
    "[+] X:", X
    x = chinese_remainder(Q, X)
    return x
