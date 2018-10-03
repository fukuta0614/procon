import re,io,sys,copy,random,time


class Sanmoku_narabe(object):

    henkan = {'a':0,'b':1,'c':2}
    marubatu = ['x','-','o']
    marubatu_let = ['MARU','BATU']

    def __init__(self):
        self.table = [0] * 9
        self.turn = 0
        self.tyn_list = []

    def calc_tyn(self):
        self.tyn_list = []
        value=0
        for i in range(3):
            for j in range(3):
                value += self.table[i*3+j]
            self.tyn_list.append(value)
            value=0

        for j in range(3):
            for i in range(3):
                value += self.table[i*3+j]
            self.tyn_list.append(value)
            value=0

        for k in range(3):
            value += self.table[k*3+k]
        self.tyn_list.append(value)
        value=0

        for l in range(3):
            value += self.table[l*3+2-l]
        self.tyn_list.append(value)

    def is_over(self):
        self.calc_tyn()
        print(self.tyn_list)
        if 3 in self.tyn_list:
            return 1
        elif -3 in self.tyn_list:
            return 2
        else:
            if not 0 in self.table:
                return 3
            else:
                return 0

    def validate(self,i,j):
        if 0 <= i < 3 and 0 <= j < 3:
            if self.table[i*3 +j] == 0:
                return True
            else:
                # print('Already Filled')
                return False
        else:
            print('Wrong number')
            return False

    def display(self):
        board = '  a b c\n0 {} {} {}\n1 {} {} {}\n2 {} {} {}\n'
        print(board.format(*list(map(lambda x:Sanmoku_narabe.marubatu[x+1],self.table))))

    def play_human_vs_human(self):
        print('Start!')
        self.display()
        while True:
            print('Turn {} {}'.format(self.turn,Sanmoku_narabe.marubatu_let[self.turn%2]))
            # user input
            while True:
                point = input("press the number >> ")
                if len(point) == 2:
                    try:
                        i,j = eval(point[0]),Sanmoku_narabe.henkan[point[1]]
                        if self.validate(i,j):
                            self.table[i*3+j] = -2*(self.turn%2) + 1
                            break
                    except:
                        pass
                else:
                    print('Two letter!')
            self.display()
            if self.is_over() == 1:
                print("MARU won")
                break
            if self.is_over() == 2:
                print("BATU won")
                break

            self.turn += 1

    def play_human_vs_ai(self):
        print('Start!')
        self.display()
        while True:
            print('Turn {} {}'.format(self.turn,Sanmoku_narabe.marubatu_let[self.turn%2]))
            # user input
            if self.turn %2 ==1:
                while True:
                    point = input("press the number >> ")
                    if len(point) == 2:
                        try:
                            i,j = eval(point[0]),Sanmoku_narabe.henkan[point[1]]
                            if self.validate(i,j):
                                self.table[i*3+j] = -2*(self.turn%2) + 1
                                break
                        except:
                            pass
                    else:
                        print('Two letter!')
            else:
                print(self.ai_calc())

            self.display()

            game = self.is_over()
            if game > 0:
                if game==1:
                    print("MARU Won")
                elif game==2:
                    print("BATU Won")
                else:
                    print('Draw Game')
                break
            else:
                self.turn += 1

    def play_ai_vs_ai(self):
        print('Start!')
        self.display()
        while True:
            print('Turn {} {}'.format(self.turn,Sanmoku_narabe.marubatu_let[self.turn%2]))

            # user input
            while True:
                i,j = (random.randint(0,2),random.randint(0,2))
                if self.validate(i,j):
                    self.table[i*3+j] = -2*(self.turn%2) + 1
                    break
            if self.turn & 2 ==0:
                print(self.ai_calc())
            self.display()

            game = self.is_over()
            if game > 0:
                if game==1:
                    print("MARU Won")
                elif game==2:
                    print("BATU Won")
                else:
                    print('Draw Game')
                break
            else:
                self.turn += 1
                time.sleep(1)

    def ai_calc(self):
        emergency = 0
        will_win = 0
        max_check = 0
        temp_i,temp_j = None,None
        for num in range(len(self.table)):
            i,j = num//3,num%3
            if self.validate(i,j):
                self.table[i*3+j] = 1
                check = self.check()
                if check == 3:
                    return 'win!!'
                elif check == 2:
                    return 'will win!'
                elif check == 0:
                    self.table[i*3+j] = 0
                    emergency = 1
                else:
                    self.table[i*3+j] = 0
                    temp_i = i
                    temp_j = j
        else:
            if emergency == 1:
                self.table[temp_i*3 + temp_j] = 1
                return 'block!'
            else:
                while True:
                    i,j = (random.randint(0,2),random.randint(0,2))
                    if self.validate(i,j):
                        self.table[i*3+j] = 1
                        break
                return 'random'

    def check(self):
        self.calc_tyn()
        if self.must_win():
            return 3
        elif self.must_lose():
            return 0
        elif self.will_win():
            return 2
        else:
            return 1

    def must_win(self):
        if 3 in self.tyn_list:
            return True
        else:
            return False
    def must_lose(self):
        if -2 in self.tyn_list:
            return True
        else:
            return False
    def will_win(self):
        if self.tyn_list.count(2) > 1:
            return True
        else:
            return False

if __name__ == '__main__':
    S = Sanmoku_narabe()
    # S.play_ai_vs_ai()
    S.play_human_vs_ai()