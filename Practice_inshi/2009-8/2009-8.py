
from collections import defaultdict

group = 'abcdefghijklmnopqrstuvwxyz'

class Board(object):

    def __init__(self):
        self.board = [ [ [] for _ in range(1000)] for _ in range(1000) ]
        self.cluster_num = 1
        self.board_cluster = [[0]*1000 for x in range(1000)]
        self.cluster_dict = {}
        # self.cluster_dict = {}

    def put(self,coord,id):

        for y in range(coord[1],coord[1]+coord[3]):
            for x in range(coord[0],coord[0]+coord[2]):
                # print(id)
                self.board[y][x].append(id)
                # self.board[y+1][x+1] += 1

    def show(self):
        for row in reversed(self.board):
            print(list(map(lambda x:len(x),row)))
        print('--------------------------------------------')
        for row in reversed(self.board_cluster):
            for cell in row:
                if cell == 0:
                    print('.',end=' ')
                else:
                    print(cell,end=' ')
            print()

    def cosolidate_botu(self):
        for y in range(len(self.board)):
            for x in range(len(self.board)):
                cluster = set()
                for id in self.board[y][x]:
                    for num,group in self.cluster_dict.items():
                        if id in group:
                            cluster.add(num)

                if len(cluster) == 0:
                    self.cluster_dict[self.cluster_num](set(self.board[y][x]))
                    self.cluster_num+=1
                elif len(cluster) == 1:
                    group = cluster.pop()
                    self.cluster_dict[group].update(self.board[y][x])
                elif len(cluster) > 1:
                    group = cluster.pop()
                    for c in cluster:
                        self.cluster_dict[group].update(self.cluster_dict.pop(c))


    def check_rec(self,i,j,cluster):
        flag = 0
        try:
            if len(self.board[i-1][j]) > 0:
                if self.board_cluster[i-1][j] == 0:
                    self.board_cluster[i-1][j] = cluster
                    self.cluster_dict[cluster].update(self.board[i-1][j])
                    self.check_rec(i-1,j,cluster)
        except:
            pass

        try:
            if len(self.board[i][j+1]) > 0:
                if self.board_cluster[i][j+1] == 0:
                    self.board_cluster[i][j+1] = cluster
                    self.cluster_dict[cluster].update(self.board[i][j+1])
                    self.check_rec(i,j+1,cluster)
        except:
            pass

        try:
            if len(self.board[i+1][j]) > 0:
                if self.board_cluster[i+1][j] == 0:
                    self.board_cluster[i+1][j] = cluster
                    self.cluster_dict[cluster].update(self.board[i+1][j])
                    self.check_rec(i+1,j,cluster)
        except:
            pass

        try:
            if len(self.board[i][j-1]) > 0:
                if self.board_cluster[i][j-1] == 0:
                    self.board_cluster[i][j-1] = cluster
                    self.cluster_dict[cluster].update(self.board[i][j-1])
                    self.check_rec(i,j-1,cluster)
        except:
            pass


    def check(self,y,x,cluster):
        to_check = [(y,x)]
        while len(to_check) > 0:
            i,j = to_check.pop(0)
            try:
                if len(self.board[i-1][j]) > 0:
                    if self.board_cluster[i-1][j] == 0:
                        self.board_cluster[i-1][j] = cluster
                        self.cluster_dict[cluster].update(self.board[i-1][j])
                        if not (i-1,j) in to_check:
                            to_check.append((i-1,j))
            except:
                pass

            try:
                if len(self.board[i][j+1]) > 0:
                    if self.board_cluster[i][j+1] == 0:
                        self.board_cluster[i][j+1] = cluster
                        self.cluster_dict[cluster].update(self.board[i][j+1])
                        if not (i,j+1) in to_check:
                            to_check.append((i,j+1))
            except:
                pass

            try:
                if len(self.board[i+1][j]) > 0:
                    if self.board_cluster[i+1][j] == 0:
                        self.board_cluster[i+1][j] = cluster
                        self.cluster_dict[cluster].update(self.board[i+1][j])
                        if not (i+1,j) in to_check:
                            to_check.append((i+1,j))
            except:
                pass

            try:
                if len(self.board[i][j-1]) > 0:
                    if self.board_cluster[i][j-1] == 0:
                        self.board_cluster[i][j-1] = cluster
                        self.cluster_dict[cluster].update(self.board[i][j-1])
                        if not (i,j-1) in to_check:
                            to_check.append((i,j-1))
            except:
                pass

    def consolidate(self):


        for y in range(len(self.board)):
            for x in range(len(self.board)):
                if len(self.board[y][x]) > 0:
                    if self.board_cluster[y][x] == 0:
                        cluster = self.cluster_num
                        self.board_cluster[y][x] = cluster
                        self.cluster_dict[cluster] = set(self.board[y][x])
                        self.check(y,x,cluster)
                        self.cluster_num += 1

    def kadai4_1_botu(self):
        target_2 = []
        for y in range(len(self.board)-10):
            for x in range(len(self.board)-5):
                flag = 0
                for i in range(10):
                    for j in range(5):
                        if self.board_cluster[y+i][x+j] == 56:
                            flag = 1
                            break
                    else:
                        continue
                    break
                if flag == 0:
                    for i in range(10):
                        try:
                            if self.board_cluster[y+i][x+5] == 56:
                                target_2.append((y,x))
                                flag = 1
                                break
                        except:
                            pass
                    if flag == 0:
                        for i in range(10):
                            if self.board_cluster[y+i][x-1] == 56:
                                target_2.append((y,x))
                                flag = 1
                                break
                        if flag == 0:
                            for j in range(5):
                                try:
                                    if self.board_cluster[y-1][x+j] == 56:
                                        target_2.append((y,x))
                                        flag = 1
                                        break
                                except:
                                    pass
                            if flag == 0:
                                for j in range(5):
                                    if self.board_cluster[y+10][x+j] == 56:
                                        target_2.append((y,x))
                                        break


    def show_section(self):
        print('  ',end=' ')
        for j in range(420,440):
            print(j,end=' ')
        print()
        for i in reversed(range(730,780)):
            print(i,end=' ')
            for j in range(420,440):
                if self.board_cluster[i][j] == 0:
                    print('...',end=' ')
                else:
                    print(self.board_cluster[i][j],end=' ')
            print()

    def result(self):

        max_thick = 0
        max_thick_point = []
        for y in range(len(self.board)):
            for x in range(len(self.board)):
                if max_thick < len(self.board[y][x]):
                    max_thick = len(self.board[y][x])
                    max_thick_point = [(y,x)]
                elif max_thick == len(self.board[y][x]):
                    max_thick_point.append((y,x))

        print('max thick',max_thick,max_thick_point)
        print('num of cluster',self.cluster_num-1)
        max_element = 0
        for key in self.cluster_dict:
            max_element = max(len(self.cluster_dict[key]),max_element)
        print('max_element',max_element)
        area_dict = defaultdict(int)

        for y in range(len(self.board)):
            for x in range(len(self.board)):
                if not self.board_cluster[y][x] == 0:
                    area_dict[self.board_cluster[y][x]] += 1
        max_area = 0
        max_cluster = 0
        for key in area_dict:
            if max_area < area_dict[key]:
                max_area = area_dict[key]
                max_cluster = key

        print('max area',max_area,max_cluster)

        target_1 = []
        for y in range(len(self.board)):
            for x in range(len(self.board)):
                for point in max_thick_point:
                    if y <= point[0] < y+10 and x <= point[1] < x+5:
                        target_1.append((y,x))
                        break

        print('target_1 ',len(target_1))


        max_add_area = 0
        max_area_point = []
        for y in range(len(self.board)-10+1):
            for x in range(len(self.board)-5+1):
                area = 0
                cluster_covered = set()
                for i in range(10):
                    for j in range(5):
                        if self.board_cluster[y+i][x+j] > 0:
                            cluster_covered.add(self.board_cluster[y+i][x+j])
                        else:
                            area += 1
                for i in range(10):
                    try:
                        if self.board_cluster[y+i][x+5] > 0:
                            cluster_covered.add(self.board_cluster[y+i][x+5])
                    except:
                        pass
                    try:
                        if self.board_cluster[y+i][x-1] > 0:
                            cluster_covered.add(self.board_cluster[y+i][x-1])
                    except:
                        pass

                for j in range(5):
                    try:
                        if self.board_cluster[y-1][x+j] > 0:
                            cluster_covered.add(self.board_cluster[y-1][x+j])
                    except:
                        pass
                    try:
                        if self.board_cluster[y+10][x+j] > 0:
                            cluster_covered.add(self.board_cluster[y+10][x+j])
                    except:
                        pass
                zero_area = area
                for cluster in cluster_covered:
                    area += area_dict[cluster]
                if area > max_add_area:
                    max_area_point = [(y,x)]
                    max_add_area = area
                    # print(zero_area,cluster_covered,max_add_area)
                elif area == max_add_area:
                    max_area_point.append((y,x))
                    # print(zero_area,cluster_covered,max_add_area)



        print('target_2 ',len(max_area_point),max_add_area)
        print(max_area_point)



def kadai13():
    with open('1000.txt') as f:
        rectangle_coords  = f.read().split('\n')

    B = Board()
    for i,coord in enumerate(rectangle_coords):
        coord = list(map(lambda x:int(x),coord.split(' ')))
        B.put(coord,i)
    B.consolidate()
    # B.show()
    B.result()
    # B.show_section()

def kadai2():
    with open('1000.txt') as f:
        rectangle_coords  = f.read().split('\n')

    area_sum = 0
    for i,coord in enumerate(rectangle_coords):
        x,y,w,h= list(map(lambda x:int(x),coord.split(' ')))
        area = w * h
        area_sum += area
    print(area_sum)

if __name__ == '__main__':
    kadai13()