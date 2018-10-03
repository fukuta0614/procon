def nazo():
    K, M = map(int, input().split())
    A = [int(x) for x in input().split()]
    C = [int(x) for x in input().split()]

    def linear_recursion_solver(a, x, k, e0, e1):
        def rec(k):
            print(k)
            c = [e0] * n
            if k < n:
                c[k] = e1
                return c[:]
            b = rec(k // 2)
            print(b)
            t = [e0] * (2 * n + 1)
            print(t)
            for i in range(n):
                for j in range(n):
                    t[i + j + (k & 1)] ^= b[i] & b[j]
            print(t)
            for i in reversed(range(n, 2 * n)):
                for j in range(n):
                    t[i - n + j] ^= a[j] & t[i]
            print(t)
            for i in range(n):
                c[i] = t[i]
                print(format(t[i], 'b'), end=', ')
            print()
            print()
            return c[:]

        n = len(a)
        c = rec(k)
        ret = 0
        for ci, xi in zip(c, x):
            ret ^= ci & xi
        return ret

    print(linear_recursion_solver(C[::-1], A, M - 1, 0, (1 << 32) - 1))


K, M = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
C = [int(x) for x in input().split()]

if M <= K:
    print(A[M - 1])
else:
    e1 = (1 << 32) - 1
    C_matrix = [C[i] for i in range(K)] + [e1 if i == j else 0 for i in range(K - 1) for j in range(K)]
    ans = A[::-1]
    bit_flag = list(format((M - K), 'b'))[::-1]

    for n, flag in enumerate(bit_flag):
        if n > 0:
            C_tmp = [0] * K ** 2
            for i in range(K):
                for j in range(K):
                    for k in range(K):
                        C_tmp[i * K + j] ^= C_matrix[i * K + k] & C_matrix[k * K + j]

            C_matrix = C_tmp[:]

        if int(flag):
            tmp = [0] * K
            for i in range(K):
                for k in range(K):
                    tmp[i] ^= C_matrix[i * K + k] & ans[k]
            ans = tmp
    print(ans[0])
