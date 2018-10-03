

#問１
#1-1 124
#1-2 134

class Controler(object):

    def __init__(self):
        self.elevetor = Elevetor()
        self.t = 0
        self.customer_id = 0
        self.customers = {}

    def control(self,demands):
        while len(self.customers) == 0 or len(demands) > 0:

            if len(demands) > 0:
                while self.t == demands[0][0]:
                    demand = demands.pop(0)
                    self.customers[self.customer_id] = Customer(*demand)
                    self.customer_id += 1
                    self.elevetor.add_demand(demand)

            self.elevetor.act()

            if self.elevetor.state == 'open_get_off':
                get_off_list = []
                for i,customer in self.customers.items():
                    if customer.dest == self.elevetor.position:
                        get_off_list.append(i)
                        print(' get off {}'.format(i))

                for p in get_off_list:
                    self.customers.pop(p)
                    self.elevetor.demand_list.pop(p)

            if self.elevetor.state == 'open_get_on':
                for i, customer in self.customers.items():
                    if customer.dem == self.elevetor.position and customer.get_on_time == 0:
                        self.customers[i].get_on_time = self.t
                        print(' get on {}'.format(i))

            print(self.t,self.elevetor.state)
            self.t += 1

class Customer(object):

    def __init__(self,time,dem,dest,direction):
        self.call_time = time
        self.get_on_time = 0
        self.get_off_time = 0
        self.dem = dem
        self.dest = dest
        self.direction = direction



class Elevetor(object):

    def __init__(self):
        self.t = 0
        self.state = 'stop'
        self.position = 1
        self.arrow = ''
        self.demand_list = {}
        self.demand_id = 0
        self.dest_list = []
        self.planning_root = []
        self.timer = 0
        self.to_move = 0

    def highest_in_demand(self):
        return max(max(self.demand_list.items(), key=lambda x: x[1]),max(self.demand_list.items(), key=lambda x: x[2]))

    def lowest_in_demand(self):
        return min(min(self.demand_list.items(), key=lambda x: x[1]),min(self.demand_list.items(), key=lambda x: x[2]))

    def add_demand(self,demand):
        self.demand_list[self.demand_id] = demand
        self.demand_id += 1
        self.make_plan()

    def make_plan(self):
        if self.arrow == '':
            self.arrow = self.demand_list[0][3]

        if self.arrow == 'up':
            upper = set()
            for i,demand in self.demand_list.items():
                if demand[1] > self.position and demand[3] == 'up':
                    upper.add(demand[1])
                    upper.add(demand[2])
            self.planning_root = upper

        if self.arrow =='down':
            pass

    def act(self):

        if self.timer > 0:
            self.timer -= 1

        if self.timer == 0:
            if self.state == 'stop' or self.state == 'close' or self.state == 'open_get_on':
                if self.position in self.demand_list:
                    self.state = 'openning'
                elif len(self.planning_root) > 0:
                    self.state = 'moving'

            elif self.state == 'openning':
                self.state = 'open_get_off'

            elif self.state == 'open_get_off':
                self.state = 'open_get_on'
                self.timer = 6

            elif self.state == 'moving_start':
                pass

        return self.state





def kadai3():
    ARROW = ['up','down']
    with open('request01.txt') as f:
        text = f.read().split("\n")
    demands = []
    for line in text[1:-1]:
        x = list(map(lambda x: int(x),line.split(' ')))
        if x[1] < x[2]:
            x.append(ARROW[0])
        if x[1] > x[2]:
            x.append(ARROW[1])
        demands.append(x)

    c = Controler()
    c.control(demands)

if __name__ == '__main__':

    kadai3()
