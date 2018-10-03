a, b, n = [int(_) for _ in input().split()]
result = [0 if x == "G" else int(x) for x in input().split()]

score = [0] * a

frame = 0
rounds = 1
res = 0

final_frame_score = []

for i, p in enumerate(result):

    if frame < (a - 1):
        if rounds == 1:
            if p == b:
                score[frame] = b + result[i + 1] + result[i + 2]
                frame += 1
            else:
                res = p
                rounds = 2
        else:
            res += p
            if res == b:
                score[frame] = b + result[i + 1]
            else:
                score[frame] = res
            res = 0
            rounds = 1
            frame += 1
    else:
        final_frame_score.append(p)

if len(final_frame_score) == 2:
    score[frame] = sum(final_frame_score)
else:
    p, q, r = final_frame_score
    if p == b:
        if q == b:
            score[frame] = 3 * b + 3 * r
        else:
            score[frame] = b + 2 * (q + r)
    else:
        score[frame] = b + 2 * r

print(sum(score))
