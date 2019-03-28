N, L, T = [int(_) for _ in input().split()]
Ants = [[int(_) for _ in input().split()] for i in range(N)]

x0, w0 = Ants[0]

zekken = 0
for x, w in Ants[1:]:
    if w == w0:
        continue

    if w0 == 1:
        dist = x - x0
        zekken += (2 * T - dist) // L + 1
        zekken %= N
    else:
        dist = L + x0 - x
        zekken -= (2 * T - dist) // L + 1
        zekken %= N


final_ants = [0] * N
for i, (x, w) in enumerate(Ants):
    if w == 1:
        final_ants[i] = (x + T) % L
    else:
        final_ants[i] = (x - T) % L

first_ant_pos = final_ants[0]

final_ants.sort()
for i in range(N):
    if final_ants[i] == first_ant_pos:
        start_idx = i - zekken
        break

for i in range(N):
    print(final_ants[(i + start_idx) % N])
