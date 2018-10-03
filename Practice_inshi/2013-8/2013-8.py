import math,time
from itertools import combinations
import pprint
root_3 = math.sqrt(3)
pp = pprint.PrettyPrinter(indent=4)


class Fractal(object):

    def __init__(self):
        self.area = 25 * root_3
        self.side_length = 10
        self.side_number = 3
        self.points = [(0,0),(5,5 * root_3),(10,0)]
        self.stage_points = [[((0,0),(5,5 * root_3),(10,0))]]
        self.depth = 0

    def proceed(self,n):
        for i in range(n):
            self._proceed()

    def _proceed(self):
        self.side_length /= 3
        self.area +=  self.side_number * self.side_length ** 2 * root_3 / 4
        self.side_number *= 4

    def make_line(self,x_1,y_1,x_2,y_2):
        a = (y_2-y_1)
        b = -(x_2-x_1)
        c = -x_1*(y_2-y_1) + y_1 * (x_2-x_1)
        return a,b,c

    def center_of_gravity(self,x_1,y_1,x_2,y_2,x_3,y_3):
        return (x_1 + x_2 + x_3) / 3,(y_1 + y_2 + y_3) / 3

    def proceed_ex(self,n):
        self.depth = n
        for i in range(n):
            self._proceed_ex()

    def _proceed_ex(self):
        new_points = []
        stage_point = []
        for i in range(len(self.points)):
            x_1,y_1 = self.points[i]
            try:
                x_2,y_2 = self.points[i+1]
            except IndexError:
                x_2,y_2 = self.points[0]
            x_a,y_a = (2 * x_1 + x_2) / 3, (2 * y_1 + y_2) / 3
            x_c,y_c = (x_1 + 2 * x_2) / 3, (y_1 + 2 * y_2) / 3
            x_b = x_a + (x_c - x_a) / 2  - root_3 * (y_c - y_a) / 2
            y_b = y_a + (y_c - y_a) / 2  + root_3 * (x_c - x_a) / 2

            stage_point.append( ((x_a,y_a),(x_b,y_b),(x_c,y_c)) )
            new_point = [(x_1,y_1),(x_a,y_a),(x_b,y_b),(x_c,y_c)]
            new_points.extend(new_point)

        self.stage_points.append(stage_point)
        self.points = new_points

    def max_rect(self):
        min_x = min(map(lambda x:x[0],self.points))
        max_x = max(map(lambda x:x[0],self.points))
        min_y = min(map(lambda x:x[1],self.points))
        max_y = max(map(lambda x:x[1],self.points))
        return min_x,max_x,min_y,max_y

    def count(self,d):
        d = abs(d)
        min_x,max_x,min_y,max_y = self.max_rect()
        # print(min_x,max_x,min_y,max_y)
        p = 0
        while p*d >= min_x:
            p -= 1
        min_p = p
        p = 0
        while p*d <= max_x:
            p += 1
        max_p = p
        q = 0
        while q*d >= min_y:
            q -= 1
        min_q = q
        q = 0
        while q*d <= max_y:
            q += 1
        max_q = q

        num = 0
        print(min_p,max_p,min_q,max_q)
        for p in range(min_p,max_p+1):
            for q in range(min_q,max_q+1):
                if self.check(p*d,q*d):
                    num += 1
        return num

    def is_include(self,x,y,point):
        # print(point)
        a_1,b_1,c_1 = self.make_line(point[0][0],point[0][1],point[1][0],point[1][1])
        a_2,b_2,c_2 = self.make_line(point[1][0],point[1][1],point[2][0],point[2][1])
        a_3,b_3,c_3 = self.make_line(point[2][0],point[2][1],point[0][0],point[0][1])
        x_g,y_g = self.center_of_gravity(point[0][0],point[0][1],point[1][0],point[1][1],point[2][0],point[2][1])

        X = (a_1*x + b_1*y + c_1) * (a_1*x_g + b_1*y_g + c_1) >= 0
        Y = (a_2*x + b_2*y + c_2) * (a_2*x_g + b_2*y_g + c_2) >= 0
        Z = (a_3*x + b_3*y + c_3) * (a_3*x_g + b_3*y_g + c_3) >= 0
        return  X and Y and Z


    def check(self,x,y):
        for stage_point in self.stage_points:
            for point in stage_point:
                if self.is_include(x,y,point):
                    return True
        return False




def kadai12(d):
    d = abs(d)
    p = 0
    while p*d <= 10:
        p+=1
    num_1 = 0
    num_2 = 0
    # print(p)
    for x in range(0,p+1):
        for y in range(0,p+1):
            if 0 <= x*d <= 10 and 0 <= y*d <= 10:
                num_1 += 1
            if ((x*d - 5)**2 + (y*d - 5)**2) <= 25:
                num_2 += 1
    print(num_1,num_2,num_2 / num_1 /4)

def kadai34(n):
    f = Fractal()
    f.proceed(n)
    print(f.area)

def kadai56(n,d):
    f = Fractal()
    s = time.time()
    f.proceed_ex(n)
    t = time.time()
    print(t - s)
    print(f.count(d))
    print(time.time() - t )

    # pp.pprint(f.stage_points)
    # pp.pprint(f.points)
def fractal_area(n):
    return 5 * root_3 * ( 8 - 3 * (4/9)**n)

if __name__ == '__main__':
    # kadai12(0.01)
    # kadai34(2)
    print(fractal_area(6))
    kadai56(6,0.1)
