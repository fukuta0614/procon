# coding: utf-8
# Your code here!
import numpy as np

H, W = [int(x) for x in input().split()]
T = [[1 if s == "#" else 0 for s in input()] for _ in range(H)]


def main():
    img = np.zeros((H + 2, W + 2)).astype("int32")
    img[1:H + 1, 1:W + 1] = T

    convert_map = {}
    segmentation = np.zeros((H + 2, W + 2)).astype("int32")

    label_num = 0

    for i in range(1, H + 1):
        for j in range(1, W + 1):
            if img[i][j]:
                if img[i - 1][j]:
                    segmentation[i][j] = segmentation[i - 1][j]

                    if img[i][j - 1]:
                        tmp = segmentation[i - 1][j]
                        while convert_map[tmp] != tmp:
                            tmp = convert_map[tmp]
                        min_label_up = tmp

                        tmp = segmentation[i][j - 1]
                        while convert_map[tmp] != tmp:
                            tmp = convert_map[tmp]
                        min_label_left = tmp

                        min_label = min(min_label_left, min_label_up)

                        tmp = segmentation[i - 1][j]
                        while True:
                            tmp2 = convert_map[tmp]
                            convert_map[tmp] = min_label
                            tmp = tmp2
                            if convert_map[tmp] == tmp:
                                convert_map[tmp] = min_label
                                break

                        tmp = segmentation[i][j - 1]
                        while True:
                            tmp2 = convert_map[tmp]
                            convert_map[tmp] = min_label
                            tmp = tmp2
                            if convert_map[tmp] == tmp:
                                convert_map[tmp] = min_label
                                break

                elif img[i][j - 1]:
                    segmentation[i][j] = segmentation[i][j - 1]
                else:
                    label_num += 1
                    segmentation[i][j] = label_num
                    convert_map[label_num] = label_num

    # label seiri
    labels = sorted(convert_map)
    final_labels = set()
    for label in labels:
        tmp = label
        while convert_map[tmp] != tmp:
            tmp = convert_map[tmp]
        convert_map[label] = tmp
        final_labels.add(tmp)

    # label seiri
    segment_count = len(final_labels)
    convert_map_last = {label: i + 1 for i, label in enumerate(sorted(list(final_labels)))}

    for label in labels:
        convert_map[label] = convert_map_last[convert_map[label]]

    # labeling
    for i in range(1, H + 1):
        for j in range(1, W + 1):
            if img[i][j]:
                segmentation[i][j] = convert_map[segmentation[i][j]]

    # answer
    ans = np.zeros((segment_count, 2)).astype("int32")
    for i in range(1, H + 1):
        for j in range(1, W + 1):
            if img[i][j]:
                ans[segmentation[i][j] - 1][0] += 1
                ans[segmentation[i][j] - 1][1] += 4 - img[i - 1][j] - img[i][j - 1] - img[i + 1][j] - img[i][j + 1]

    ans = sorted(ans, key=lambda x: (-x[0], -x[1]))

    ans = [(int(p), int(q)) for p, q in ans]
    for row in ans:
        print(*row)


if __name__ == '__main__':
    main()


