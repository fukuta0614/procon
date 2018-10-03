K, s, t = [int(_) for _ in input().split()]


def calc_length(k):
    return 3 * (2 ** k - 1)


def calc_half_length(k):
    return calc_length(k - 1) + 2


def get_char(pos, k):
    length = calc_length(k)
    half_length = calc_half_length(k)

    if pos == 1:
        return "A"
    elif pos < half_length:
        return get_char(pos - 1, k - 1)
    elif pos == half_length:
        return "B"
    elif pos < length:
        return get_char(pos - half_length, k - 1)
    elif pos == length:
        return "C"
    else:
        raise ValueError


ans = []
for pos in range(s, t+1):
    ans.append(get_char(pos, K))

print("".join(ans))
