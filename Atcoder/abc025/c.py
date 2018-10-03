b = [[int(_) for _ in input().split()] for i in range(2)]
c = [[int(_) for _ in input().split()] for i in range(3)]


def calc(board):
    maru, batu = 0, 0
    for i in range(2):
        for j in range(3):
            if board[i * 3 + j] == board[(i + 1) * 3 + j]:
                maru += b[i][j]
            else:
                batu += b[i][j]

    for i in range(3):
        for j in range(2):
            if board[i * 3 + j] == board[i * 3 + j + 1]:
                maru += c[i][j]
            else:
                batu += c[i][j]
    return maru, batu


memo = dict()
def traverse(board, turn):
    if tuple(board) in memo:
        return memo[tuple(board)]

    if 0 not in board:
        return calc(board)

    max_score = 0, 0
    for i in range(9):
        if board[i] == 0:
            new_board = board[:]
            new_board[i] = turn
            maru, batu = traverse(new_board, turn * -1)
            if turn == 1:
                if maru >= max_score[0]:
                    max_score = maru, batu
            else:
                if batu >= max_score[1]:
                    max_score = maru, batu

    memo[tuple(board)] = max_score
    return max_score


board = [0] * 9
turn = 1
max_score = traverse(board, turn)
print(max_score[0])
print(max_score[1])
