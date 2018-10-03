from collections import defaultdict, OrderedDict
from itertools import combinations
import pprint,time,os,sys,math,copy,re,random

pp = pprint.PrettyPrinter(indent=4)

alphabet = 'abcdefghijklmnopqrstuvwxyz'


# with open('') as f:
#     txt = f.read().split('\n')[:-1]

def kadai2():
    N = int(input())
    p = list(map(int,input().split()))

    # N = 5
    # p = [1 ,2, 3, 4, 5]
    # print(N,p)

    graph = dict(zip(range(1,N+1),p))
    # print(graph)

    rest = set(range(1,N+1))
    s = 1
    group = set()
    group_num = 0
    while True:
        group.add(s)
        d = graph[s]
        if d in group:
            # print(group)
            group_num += 1
            rest -= group
            if len(rest) == 0:
                break
            group = set()
            s = list(rest)[0]
        else:
            s = d

    print(group_num)

def kadai2_tomi():
    import networkx as nx

    N = int(input())
    to = list(map(int, input().split()))
    from_ = range(1, N + 1)

    vector = dict(zip(from_, to))

    G = nx.Graph(vector)

    print(nx.number_connected_components(G))

from itertools import combinations
import copy

class Board(object):

    def __init__(self, board):
        self.board = board
        self.sum_column = []
        for j in range(6):
            num = 0
            for i in range(6):
                num += self.board[i][j]
            self.sum_column.append(num)

    def check_hard(self, sum_column):
        for sum in sum_column:
            if sum != 3:
                return False
        return True

    def check_soft(self, sum_column):
        for sum in sum_column:
            if sum > 3:
                return False
        return True


    def count_main(self):
        return self.count(0)

    def count(self, row, sum_column_old=None):

        if sum(self.board[row]) == 0:

            num = 0
            for a,b,c in combinations(range(6),3):
                if sum_column_old is None:
                    sum_column = self.sum_column.copy()
                else:
                    sum_column = sum_column_old.copy()
                sum_column[a] += 1
                sum_column[b] += 1
                sum_column[c] += 1
                if row == 5:
                    if self.check_hard(sum_column):
                        num += 1
                    else:
                        num += 0
                else:
                    if self.check_hard(sum_column):
                        num += 1
                    else:
                        if self.check_soft(sum_column):
                            num += self.count(row+1,sum_column)
            # print(num)
            return num

        if sum(self.board[row]) == 1:

            num = 0
            for a,b in combinations(range(6),2):
                if self.board[row][a] == 1 or self.board[row][b] == 1:
                    continue
                if sum_column_old is None:
                    sum_column = self.sum_column.copy()
                else:
                    sum_column = sum_column_old.copy()
                sum_column[a] += 1
                sum_column[b] += 1
                if row == 5:
                    if self.check_hard(sum_column):
                        num += 1
                    else:
                        num += 0
                else:
                    if self.check_hard(sum_column):
                        num += 1
                    else:
                        if self.check_soft(sum_column):
                            num += self.count(row+1,sum_column)
            # print(num)
            return num

        if sum(self.board[row]) == 2:

            num = 0
            for a in range(6):
                if self.board[row][a] == 1:
                    continue
                if sum_column_old is None:
                    sum_column = self.sum_column.copy()
                else:
                    sum_column = sum_column_old.copy()
                sum_column[a] += 1
                if row == 5:
                    if self.check_hard(sum_column):
                        num += 1
                    else:
                        num += 0
                else:
                    if self.check_hard(sum_column):
                        num += 1
                    else:
                        if self.check_soft(sum_column):
                            num += self.count(row+1,sum_column)
            # print(num)
            return num

        if sum(self.board[row]) == 3:
            if sum_column_old is None:
                    sum_column = self.sum_column.copy()
            else:
                sum_column = sum_column_old.copy()
            return self.count(row+1,sum_column)

        if sum(self.board[row]) > 3:
            return 0

def kadai3():
    board = []
    for i in range(6):
        board.append(list(map(lambda x: 1 if x=='o' else 0, input())))
    t = time.time()
    B = Board(board)
    print(B.sum_column)
    # koma_list = []
    print(B.count_main())
    print(time.time()-t)

def kadai4():
    K = int(input())
    a = list(map(int,input().split()))
    p = []
    for x in a:
        p.append(x/sum(a))
    print(p)
    E = 0
    for i in range(2, 10000):
        E += i * (p[0] * p[1]**(i-1) + p[1] * p[0]**(i-1))
    print(E)

if __name__ == '__main__':
    # kadai2_tomi()
    import time
    kadai3()
