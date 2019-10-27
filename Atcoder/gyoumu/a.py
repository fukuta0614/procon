import numpy as np
import pulp
from pulp import LpVariable as Var
from pulp import lpSum
import time

def make_input():
    unit_num = np.random.randint(20, 72)
    unit_num_each_max = [10, 10, 10, 10, 10, 10, 8, 8, 5, 5]
    unit_kind_num = 10

    input_list = []
    tmp = unit_num
    for i in range(unit_kind_num-1):
        num = np.random.randint(0, min(unit_num_each_max[i], tmp))
        tmp -= num
        input_list.append(num)

    input_list.insert(0, tmp)
    return input_list

def solve(input_list):

    units_info = [["TH", 12],
                  ["HA", 33],
                  ["HV", 30],
                  ["ST", 30],
                  ["CA", 38],
                  ["FV", 40],
                  ["CAN", 16],
                  ["EN0", 16],
                  ["EN6", 76],
                  ["EN12", 136]]
    cost_info = [b for a, b in units_info]

    # ユニット数
    unit_num = sum(input_list)
    # 最大リモート数
    max_remote_num = 9
    # 入力ユニットの重み
    costs = [cost_info[i] for i in range(len(input_list)) for j in range(input_list[i])]
    # 各ユニットに入れられる数
    num_cap = [8, 8, 8, 8, 8, 8, 8, 8, 8]
    # 各ユニットに入れられる重みの容量
    watt_cap = [200, 200, 200, 200, 200, 200, 200, 200, 200]

    # CANユニットのindex
    can_indices = list(range(sum(input_list[:6]), sum(input_list[:6])+input_list[6]))
    # ENユニットのindex
    en_indices = list(range(sum(input_list[:7]), unit_num))

    # 逆引き用index
    transpose_indices = [i for i in range(len(input_list)) for j in range(input_list[i])]

    print(unit_num)
    print(input_list)
    print(costs)


    def branch_and_bound(remote_num):
        ## 問題の宣言
        prob = pulp.LpProblem(sense=pulp.LpMinimize)

        # ユニットの数
        N = unit_num
        # 箱の数
        M = remote_num
        # 接続できるCANの数
        can_master_max = 4
        can_remote_max = 4 if remote_num <= 3 else 2
        # 接続できるENの数
        en_max = 4

        ## 変数の宣言
        x = []
        for i in range(N):
            tmp = []
            for j in range(M):
                var = Var(name='x{}_{}'.format(i, j), cat='Binary')
                tmp.append(var)
            x.append(tmp)

        y = Var(name='y', cat='Integer')

        ##  目的関数
        prob += y

        ## 制約
        prob += y >= 0

        # 全部割り当てられること
        for i in range(N):
            prob += lpSum([x[i][j] for j in range(M)]) == 1
        # 各8個まで
        for j in range(M):
            prob += lpSum([x[i][j] for i in range(N)]) <= num_cap[j]
        # それぞれの容量以下
        for j in range(M):
            prob += lpSum([x[i][j] * costs[i] for i in range(N)]) <= (watt_cap[j] + y)

        # CAN制約
        prob += lpSum([x[idx][0] for idx in can_indices]) <= can_master_max
        for j in range(1, M):
            prob += lpSum([x[idx][j] for idx in can_indices]) <= can_remote_max

        # EN制約
        for j in range(M):
            prob += lpSum([x[idx][j] for idx in en_indices]) <= en_max

        ## ソルバー実行
        solver = pulp.PULP_CBC_CMD(maxSeconds=1)
        prob.solve(solver=solver)
        status = prob.status
        ret = status == 1 and y.value() == 0

        if ret:
            print("最小は {} 個".format(remote_num))
            for j in range(M):
                units = [costs[i] for i in range(N) if x[i][j].value() == 1]
                units_name = [units_info[transpose_indices[i]][0] for i in range(N) if x[i][j].value() == 1]
                n = sum([x[i][j].value() for i in range(N)])
                sm = sum(units)
                units = ["{:3d}".format(c) for c in units]
                units_name = [c.rjust(4) for c in units_name]
                for i in range(8 - len(units)):
                    units.append("   ")
                    units_name.append("   ")
                ret1 = ", ".join(units)
                ret2 = ", ".join(units_name)
                print("リモート{} には {}個 計 {} [{}] [{}]".format(j, n, sm, ret1, ret2))
        else:
            print("{}は無理".format(remote_num), status, y.value())

        return ret

    ## loop
    for remote_num in range(1, max_remote_num+1):
        s = time.time()
        ret = branch_and_bound(remote_num)
        print(time.time() - s)
        if ret:
            break
    else:
        remote_num = -1

    return remote_num


if __name__ == '__main__':

    s = []
    for i in range(1):
        input_list = make_input()
        ret = solve(input_list)
        s.append((input_list, ret))

    # with open("arg.txt", 'w') as f:
    #     for i in range(100):
    #         f.write(" ".join([str(a) for a in s[i][0]]) + "\n")
    #         f.write(str(s[i][1]) + "\n")

