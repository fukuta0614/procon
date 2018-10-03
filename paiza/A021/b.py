# coding: utf-8
# A021:海岸線
from operator import itemgetter

H, W = [int(i) for i in input().split()]
s = [[str(j) for j in input()] for i in range(H)]
# print("H,W",H,W)
# print("s",s)

line_i = 0
view = []
for line in s:
    if "#" in line:
        for j in range(W):
            if s[line_i][j] == "#":
                view.append((line_i, j))
    line_i += 1

# print("view",view)
# 島の面積、海岸線の長さを、島の面積が大きい順に以下の順で出力

view_tmp = view[:]
# 俯瞰図から島を見つける
# 見つけた島の面積、海岸線の長さ島情報として島に付加して保存
# また新たに島を見つける・・・を繰り返す
# 俯瞰図の端まで上記を行ったら、島情報から最も島の面積が大きい順に並び替える


# 俯瞰図から島を見つける
# 俯瞰図から陸地を探す
# 陸地を見つけたらそこから地続きの陸地を見つける
# 地続きの陸地を全て見つけたらそれを島と断定する
# 俯瞰図から見つけた島を取り除く
island = set()
islands = []
while (True):
    if len(view_tmp) == 0:  # 全ての陸地を島に分別した
        break
    view = view_tmp[:]

    line = view[0][0]
    row = view[0][1]
    for i in range(row, W):
        if (line, i) in view:  # 同行に地続きの陸地がある場合
            # print("add1")
            island.add((line, i))  # 島として保存
        else:
            break
    # 次に, 見つけた陸地から下の行を参照して、上下の行,もしくは左右の列が地続きに接している陸地を追加する
    for next_line in range(line + 1, H):
        for l in range(W):
            if (next_line, l) in view:
                # 上の行の陸地と地続きの陸地を見つける
                if (next_line - 1, l) in island:
                    island.add((next_line, l))
                    # その陸地から左右に伸びる陸地を島として保存
                    for m in range(l + 1, W):
                        if (next_line, m) in view:
                            island.add((next_line, m))
                        else:  # 途切れたら終了
                            break
                    for n in range(l - 1, -1, -1):
                        if (next_line, n) in view:
                            island.add((next_line, n))
                        else:  # 途切れたら終了
                            break
    # print("island", island)
    coastline = 0
    # 島の最も上端の行
    upline = min([row[0] for row in list(island)])
    flg = 0
    # islandの海岸線の長さを計測する
    for i in range(H):
        for j in range(W):
            if (i, j) in island:
                flg = 4
                # 島の左右上下の海岸線を計測
                if (i, j + 1) in island:  # 右が陸地
                    flg -= 1
                if (i, j - 1) in island:  # 左が陸地
                    flg -= 1
                if (i + 1, j) in island:  # 下が陸地
                    flg -= 1
                if (i - 1, j) in island:  # 上が陸地
                    flg -= 1
                coastline += flg

    # print("coastline",coastline)
    # 島と判定された陸地を俯瞰図から削除
    view_tmp = list(set(view).difference(island))
    view_tmp.sort(key=itemgetter(0, 1))
    # print("view_tmp",view_tmp)
    # 島の情報を記録
    islands.append((len(island), coastline))
    island = set()
# print(islands)

# 面積の大きい順に並べる
islands.sort()
islands.reverse()
for i in islands:
    print(str(i[0]) + " " + str(i[1]))
