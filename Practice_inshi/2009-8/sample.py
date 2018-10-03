for i in range(10):
    print(i)
else:
    print('asdf')


class Sample(object):
    def __init__(self,start):
        self.status = start
        self.n = len(self.status)


    def func(self):
        temp = None
        count = 1
        temp_index = 0
        print(self.status)
        for i,x in enumerate(list(self.status)):
            print(x)
            if x == temp:
                count += 1
            else:
                if count >= 3:
                    if temp == 0:
                        self.status.insert(temp_index,0)
                        self.n += 1
                    if temp == 1:
                        self.status.pop(temp_index)
                        self.n -= 1

                temp = x
                temp_index = i
                count = 1
        print(self.status)
