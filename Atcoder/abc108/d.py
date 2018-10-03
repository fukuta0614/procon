import math

L = int(input())


def main():
    n = int(math.log2(L))
    N = n + 1

    edges = []
    for i in range(1, N):
        edges.append((i, i + 1, 0))
        edges.append((i, i + 1, 2 ** (n - i)))

    res = L - 2 ** n
    bits = bin(res)[2:]
    weight = 2 ** n
    for i, bit in enumerate(bits):
        if int(bit):
            edges.append((1, i + 2, weight))
            weight += 2 ** (n - i - 1)

    print(N, len(edges))
    for row in edges:
        print(*row)



def main2(L):
    n = int(math.log2(L))
    N = n + 1

    edges = []
    for i in range(1, N):
        edges.append((i, i + 1, 0))
        edges.append((i, i + 1, 2 ** (n - i)))

    res = L - 2 ** n
    bits = bin(res)[2:]
    weight = 2 ** n
    for i, bit in enumerate(bits):
        if int(bit):
            edges.append((1, i + 2, weight))
            weight += 2 ** (n - i - 1)

    return N, edges


if __name__ == '__main__':
    main()
