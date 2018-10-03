from getch import getch,pause
import random,threading,time,os
# 0 ' '
# 1 '.'
# 2 'X'


BOARD = '''
\r| - - - V - - - |
\r| {} {} {} {} {} {} {} |
\r| {} {} {} {} {} {} {} |
\r| {} {} {} {} {} {} {} |
\r| {} {} {} {} {} {} {} |
\r| {} {} {} {} {} {} {} |
\r| {} {} {} {} {} {} {} |
\r| {} {} {} {} {} {} {} |
\r| {} {} {} {} {} {} {} |
\r| {} {} {} {} {} {} {} |
\r| {} {} {} {} {} {} {} |
\r| {} {} {} {} {} {} {} |
\r| {} {} {} {} {} {} {} |
\r| {} {} {} {} {} {} {} |
\r| {} {} {} {} {} {} {} |    SCORE {}  MISS {}
'''
PLAYER = ['.'] * 7

class Enemy(object):

    def __init__(self):
        self.point = [0,random.randint(0,6)]
        self.direction = 1
    def move(self):

        if self.point[1] == 6:
            self.direction = -1
        if self.point[1] == 0:
            self.direction = 1
        self.point[1] += self.direction

        self.point[0] += 1
        return self.point
        # if self.point[0] > 12:
        #     return False
        # else:
        #     return True

    def get_point(self):
        return self.point

class Bullet(object):
    def __init__(self,x):
        self.point = [13,x]
        self.fin = 0

    def move(self,enemy_point):
        self.point[0] += -1

        if self.point == enemy_point:
            self.fin = 1
            return True

        if self.point[0] < 0:
            self.fin = 1
        return False

    def get_point(self):
        return self.point

class Invader(object):

    def __init__(self):
        self.board = [' '] * 91+  ['.'] * 3 + ['X'] + ['.'] * 3 + [0] *2
        self.enemy = None
        self.enemy_count = 0
        self.player = 3
        self.bullet = []
        self.bullet_point = []
        self.score = 0
        self.thread = threading.Thread(target=self.play_auto)
        self.thread.start()

    def draw_enemy(self):
        if not self.enemy is None:
            self.board[self.enemy.point[0]*7+self.enemy.point[1]] = 'o'

    def draw_bullet(self):
        for bullet in self.bullet:
            self.board[bullet.point[0]*7+bullet.point[1]] = 'c'

    def display(self):
        self.draw_enemy()
        self.draw_bullet()
        # if not self.enemy is None:
        #     print(self.enemy.point,self.enemy.direction)
        # for s in self.bullet:
        #     print(s.point)
        os.system('clear')
        print(BOARD.format(*self.board))


    def play(self):
        self.display()
        while True:
            if self.score > 4:
                print('Congratulation!!!')
                exit()
            if self.enemy_count > 4:
                print('Game Over')
                exit()
            while True:
                key = getch()
                if key == 'i':
                    if len(self.bullet) < 2:
                        self.bullet.append(Bullet(self.player))
                    break
                elif key == 'j':
                    if self.player > 0:
                        self.player += -1
                    break
                elif key == 'l':
                    if self.player < 6:
                        self.player += 1
                    break
                elif key == 'k':
                    break
                elif key == '0':
                    print('Bye')
                    exit()
                else:
                    continue
            time.sleep(0.5)
            player_field = ['.'] * 7
            player_field[self.player] = 'X'
            self.board = [' '] * 91 + player_field + [self.score] + [self.enemy_count]
            if self.enemy is None:
                self.enemy = Enemy()
            else:
                point= self.enemy.move()
                if point[0]==13:
                    self.enemy = None
                    self.enemy_count += 1

            if len(self.bullet) > 0:
                for bullet in self.bullet:
                    if self.enemy is None:
                        point = [-1,-1]
                    else:
                        point = self.enemy.point
                    if bullet.move(point) > 0:
                        self.board[point[0]*7+point[1]] = '*'
                        self.score += 1
                        self.enemy = None


            bullet_list = []
            for bullet in self.bullet:
                if bullet.fin == 0:
                    bullet_list.append(bullet)
            self.bullet = bullet_list



            self.display()

    def keyboard_func(self):
        global key
        while True:
            key = getch()
            if key == '0':
                break

    def play_auto(self):
        self.display()
        global key
        key = ''
        temp = time.time()
        while True:
            if self.score > 4:
                print('Congratulation!!!')
                exit()
            if self.enemy_count > 4:
                print('Game Over')
                exit()


            if time.time() - temp > 0.5:
                temp = time.time()

                if key == 'i':
                    if len(self.bullet) < 2:
                        self.bullet.append(Bullet(self.player))
                elif key == 'j':
                    if self.player > 0:
                        self.player += -1
                elif key == 'l':
                    if self.player < 6:
                        self.player += 1
                elif key == '0':
                    print('Bye')
                    exit()
                player_field = ['.'] * 7
                player_field[self.player] = 'X'
                self.board = [' '] * 91 + player_field + [self.score] + [self.enemy_count]
                if self.enemy is None:
                    self.enemy = Enemy()
                else:
                    point= self.enemy.move()
                    if point[0]==13:
                        self.enemy = None
                        self.enemy_count += 1

                if len(self.bullet) > 0:
                    for bullet in self.bullet:
                        if self.enemy is None:
                            point = [-1,-1]
                        else:
                            point = self.enemy.point
                        if bullet.move(point) > 0:
                            self.board[point[0]*7+point[1]] = '*'
                            self.score += 1
                            self.enemy = None


                bullet_list = []
                for bullet in self.bullet:
                    if bullet.fin == 0:
                        bullet_list.append(bullet)
                self.bullet = bullet_list


                self.display()
                key = None

if __name__ == '__main__':

    i = Invader()
    i.keyboard_func()
    # i.play()