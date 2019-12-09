
N = 12
P = 3

def test1():
    for i in range(P**(N-2)):

        n = i
        tmp = [[1], [2], []]
        for j in range(3, N+1):
            tmp[n%P].append(j)
            n //= P

        flag = True
        for j in range(P):
            for x in tmp[j]:
                for y in tmp[j]:
                    if x + y in tmp[j]:
                        flag = False
                        break

        if flag:
            print(tmp)

import copy

def test2():
    tmp = [[] for i in range(P)]
    tmp[0].append(1)
    tmp[1].append(2)

    ans = []
    def dfs(n):
        if n == N+1:
            ans.append(copy.deepcopy(tmp))
            return

        for i in range(P):
            tmp[i].append(n)
            flag = True
            for x in tmp[i]:
                for y in tmp[i]:
                    if x + y in tmp[i]:
                        flag = False
                        break
                else:
                    continue
                break
            if flag:
                dfs(n+1)

            tmp[i].pop()

    dfs(3)

    for res in ans:
        print(res)


if __name__ == '__main__':
    # test1()
    test2()