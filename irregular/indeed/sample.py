
from itertools import combinations
import copy

class Board(object):

    def __init__(self, board):
        self.board = board

    def check_hard(self, board):
        for i in range(6):
            # print(sum(self.board[i]))
            if sum(board[i]) != 3:
                return False

        for j in range(6):
            num = 0
            for i in range(6):
                num += board[i][j]
            if num != 3:
                return False
        return True

    def check_soft(self, board):
        for i in range(6):
            # print(sum(self.board[i]))
            if sum(board[i]) > 3:
                return False

        for j in range(6):
            num = 0
            for i in range(6):
                num += board[i][j]
            if num > 3:
                return False
        return True


    def count_main(self):
        return self.count(0)

    def count(self, row, board=None):

        if board is None:
            board = self.board
        if sum(board[row]) == 0:
            num = 0
            for a,b,c in combinations(range(6),3):
                if board is None:
                    new_board = copy.deepcopy(self.board)
                else:
                    new_board = copy.deepcopy(board)
                new_board[row][a] = 1
                new_board[row][b] = 1
                new_board[row][c] = 1
                if row == 5:
                    if self.check_hard(new_board):
                        num += 1
                    else:
                        num += 0
                else:
                    if self.check_hard(new_board):
                        num += 1
                    else:
                        if self.check_soft(new_board):
                            num += self.count(row+1,new_board)
            # print(num)
            return num

        if sum(board[row]) == 1:
            num = 0
            for a,b in combinations(range(6),2):
                if board is None:
                    new_board = copy.deepcopy(self.board)
                else:
                    new_board = copy.deepcopy(board)
                if new_board[row][a] == 1 or new_board[row][b] == 1:
                    continue
                new_board[row][a] = 1
                new_board[row][b] = 1
                if row == 5:
                    if self.check_hard(new_board):
                        num += 1
                    else:
                        num += 0
                else:
                    if self.check_hard(new_board):
                        num += 1
                    else:
                        if self.check_soft(new_board):
                            num += self.count(row+1,new_board)
            # print(num)
            return num

        if sum(board[row]) == 2:
            num = 0
            for a in range(6):
                if board is None:
                    new_board = copy.deepcopy(self.board)
                else:
                    new_board = copy.deepcopy(board)
                if new_board[row][a] == 1:
                    continue
                new_board[row][a] = 1
                if row == 5:
                    if self.check_hard(new_board):
                        num += 1
                    else:
                        num += 0
                else:
                    if self.check_hard(new_board):
                        num += 1
                    else:
                        if self.check_soft(new_board):
                            num += self.count(row+1,new_board)
            # print(num)
            return num

        if sum(board[row]) == 3:
            return self.count(row+1,board)

        if sum(board[row]) > 3:
            return 0

board = []
for i in range(6):
    board.append(list(map(lambda x: 1 if x=='o' else 0, input())))
B = Board(board)
# koma_list = []
print(B.count_main())