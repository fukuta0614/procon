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
