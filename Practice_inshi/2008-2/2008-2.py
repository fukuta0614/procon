
from collections import defaultdict, OrderedDict
from itertools import combinations,groupby
import pprint,time,os,sys,math,copy,re,random

pp = pprint.PrettyPrinter(indent=4)

alphabet = 'abcdefghijklmnopqrstuvwxyz'


# with open('') as f:
#     txt = f.read().split('\n')[:-1]
to_print = ['.','#']
junban  = '111 110 101 100 011 010 001 000'
#           0   1   2   3   4   5   6   7

def binary(n):
    a = ''
    while(n > 0):
        a = str(n%2) + a
        n //= 2
    if len(a) < 8:
        a = '0'*(8-len(a)) + a
    return a

def kadai1():
    #255,240
    pass

def revert(n):
    bit  = list(binary(n))
    bit[1],bit[4] = bit[4],bit[1]
    bit[3],bit[6] = bit[6],bit[3]
    return int(''.join(bit),2)

def kadai2():
    #16,64
    count = 0
    for i in range(256):
        if i == revert(i):
            count += 1
    print(count)


class Simulator(object):

    def __init__(self,n,M,start_status):
        self.n = n
        self.M = M
        self.func = OrderedDict(zip(junban.split(' '),map(lambda x:int(x),list(binary(M)))))
        self.status = start_status
        self.left_center_right = [0] * n

    def calc_left_center_right(self):
        for i in range(self.n):
            if i == 0:
                self.left_center_right[0] = '{}{}{}'.format(self.status[-1],self.status[0],self.status[1])
            elif i == self.n-1:
                self.left_center_right[self.n-1] = '{}{}{}'.format(self.status[self.n-2],self.status[self.n-1],self.status[0])
            else:
                self.left_center_right[i] = '{}{}{}'.format(self.status[i-1],self.status[i],self.status[i+1])
    def simulate(self):
        print(binary(self.M))
        print(self.func)
        t = 0
        print(''.join(map(lambda x:to_print[int(x)],self.status)))
        while True:
            t += 1
            self.calc_left_center_right()
            for i in range(self.n):
                self.status[i] = self.func[self.left_center_right[i]]

            print(''.join(map(lambda x:to_print[x],self.status)))

            if t == 10:
                break

class Simulator_ex(object):

    def __init__(self,n,M,start_status):
        self.M = M
        self.func = OrderedDict(zip(junban.split(' '),map(int,list(binary(M)))))
        self.status = start_status
        self.left_center_right = []

    def calc_left_center_right(self):
        n = len(self.status)
        self.left_center_right = [0] * n
        for i in range(n):
            if i == 0:
                self.left_center_right[0] = '{}{}{}'.format(self.status[-1],self.status[0],self.status[1])
            elif i == n-1:
                self.left_center_right[n-1] = '{}{}{}'.format(self.status[n-2],self.status[n-1],self.status[0])
            else:
                self.left_center_right[i] = '{}{}{}'.format(self.status[i-1],self.status[i],self.status[i+1])

    def apply_added_rule(self):
        temp = None
        count = 1
        temp_index = 0
        i = 0
        j = 0
        # print(self.status)

        if self.status[0] == 1 and  self.status[-1] == 1:
            i = 0
            j = -1
            flag = True
            while flag:
                flag = False
                if self.status[i+1] == 1:
                    flag = True
                    i += 1
                if self.status[j-1] == 1:
                    flag = True
                    j -= 1
                if i > len(self.status)+j:
                    self.status.pop()
                    return
            if i - j >= 2:
                self.status.pop(j)
                i += 1
                j += 1


        elif self.status[0] == 0 and  self.status[-1] == 0:
            i = 0
            j = -1
            flag = True
            while flag:
                flag = False
                if self.status[i+1] == 0:
                    flag = True
                    i += 1
                if self.status[j-1] == 0:
                    flag = True
                    j -= 1
                if i == len(self.status)+j:
                    self.status.insert(0,1)
            if i - j >= 2:
                self.status.insert(j,0)
                i += 1
                j -= 1

        else:
            pass
        # print(self.status,i,j)
        while i < len(self.status)+j:
            if self.status[i] == temp:
                count += 1
                i += 1
            else:
                if count >= 3:
                    if temp == 0:
                        self.status.insert(temp_index,0)

                        temp = 1
                        temp_index = i + 1
                        i += 2
                        count = 1
                    elif temp == 1:
                        self.status.pop(temp_index)

                        temp = 0
                        temp_index = i - 1
                        i += 0
                        count = 1
                else:
                    temp = self.status[i]
                    temp_index = i
                    count = 1
                    i += 1
            # print(i-1,self.status,temp,count)
        if count >= 3:
            if temp == 0:
                self.status.insert(temp_index,0)

            elif temp == 1:
                self.status.pop(temp_index)

    def apply_added_rule_ex(self):

        new_status = []
        # print(self.status)
        # for k,g in groupby(self.status):
        #     print(k,list(g))

        d = [(key, list(group)) for key, group in groupby(self.status)]

        if len(d) == 1:
            if d[0][0] == 1:
                self.status.pop()
            elif d[0][0] == 0:
                self.status.insert(0,0)
            return

        first_digit,first_group = d[0][0],d[0][1]
        last_digit, last_group = d[-1][0],d[-1][1]

        to_extend = None
        if len(first_group)+len(last_group) >= 3:
            if first_digit == 1 and last_digit == 1:
                to_extend = last_group[:-1]

            elif first_digit == 0 and last_digit == 0:
                to_extend = last_group + [0]


        if to_extend is None:
            for k,group in d:
                if len(group) < 3:
                    new_status.extend(group)
                else:
                    if k == 0:
                        new_status.extend(group + [0])
                    else:
                        new_status.extend(group[:-1])
        else:
            for k,group in d[1:-1]:
                if len(group) < 3:
                    new_status.extend(group)
                else:
                    if k == 0:
                        new_status.extend(group + [0])
                    else:
                        new_status.extend(group[:-1])
            new_status = first_group + new_status + to_extend
        self.status = new_status

    def simulate(self):
        print(binary(self.M))
        print(self.func)
        t = 0
        print(''.join(map(lambda x:to_print[int(x)],self.status)))
        while True:
            n = len(self.status)
            t += 1
            self.calc_left_center_right()
            for i in range(n):
                self.status[i] = self.func[self.left_center_right[i]]
            # print(t,''.join(map(lambda x:to_print[x],self.status[:100])))

            self.apply_added_rule()

            print(t,''.join(map(lambda x:to_print[x],self.status[:100])))

            if len(self.status) < 3 or len(self.status) > 2000:
                print('size-out-of-range')
                break

            if t == 50:
                break
def kadai3():

    #3-1
    # start = [0] * 100
    # start[40] = 1
    # s = Simulator(100,90,start)

    #3-2
    # start = []
    # for i in range(123):
    #     if binary(i).count('1') == 3:
    #         start.append(1)
    #     else:
    #         start.append(0)
    # s = Simulator(123,99,start)

    #3-3
    start = []
    for i in range(1,41):
        start.extend([0]*i + [1])
    s = Simulator(860,129,start)

    s.simulate()

def kadai4():
    #4-1
    # start = []
    # for i in range(100):
    #     if binary(i).count('1') == 3:
    #         start.append(1)
    #     else:
    #         start.append(0)
    # s = Simulator_ex(100,53,start)
    #4-2
    start = []
    for i in range(1,41):
        start.extend([0]*i + [1])

    s = Simulator_ex(65,250,start[:65])

    s.simulate()

if __name__ == '__main__':
    # kadai1()
    # kadai2()
    # kadai3()
    kadai4()


