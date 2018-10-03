from collections import defaultdict
import copy,time
import pprint
pp = pprint.PrettyPrinter(indent=4)


class Node(object):

    def __init__(self,int):
        pass

# def achieve(achieve_set,edge_dict):

def kadai1():
    with open('a.txt') as f:
        a = f.read().split('\n')
    node_set = set()
    edge_out_dict = defaultdict(list)
    edge_in_dict = defaultdict(list)
    reachable_list = set()
    reachable_list.add(0)
    temp_1 = 0
    temp_2 = 0
    reach_flag = 0

    for t in range(len(a)):
        x,y = a[t].split('->')
        x,y = int(x),int(y)
        edge_out_dict[x].append(y)
        edge_in_dict[y].append(x)
        node_set.add(x)
        node_set.add(y)
        temp = 0
        while True:
            for node in edge_out_dict:
                if node in reachable_list:
                    if 0 in edge_out_dict[node] and reach_flag == 0:
                        print('cycle!',t)
                        reach_flag = 1
                    reachable_list.update(edge_out_dict[node])
            if temp == len(reachable_list):
                break
            temp = len(reachable_list)

        if len(node_set) >= 1000 and temp_1 < 1000:
            print('V over 1000!',t,temp_1,len(node_set))
        temp_1 = len(node_set)

        if len(reachable_list) >= 1000 and temp_2 < 1000:
            print('R over 1000!',t,temp_2,len(reachable_list))
        temp_2 = len(reachable_list)

    print(len(node_set))
    max_in = 0
    max_in_node = 0
    max_out = 0
    max_out_node = 0
    for node in edge_out_dict:
        if len(edge_out_dict[node]) > max_out:
            max_out_node = node
            max_out = len(edge_out_dict[node])

    for node in edge_in_dict:
        if len(edge_in_dict[node]) > max_in:
            max_in_node = node
            max_in = len(edge_in_dict[node])
    print('max_out',max_out_node,max_out)
    print('max_in',max_in_node,max_in)

def kadai2():
    with open('b.txt') as f:
        a = f.read().split('\n')
    node_set = set()
    edge_out_dict = defaultdict(list)
    edge_in_dict = defaultdict(list)
    reachable_list = set()
    reachable_list.add(0)
    temp_1 = 0
    temp_2 = 0
    reach_flag = 0

    for t in range(len(a)):
        if '!' in a[t]:
            x,y = a[t][1:].split('->')
            x,y = int(x),int(y)
            edge_out_dict[x].remove(y)
            edge_in_dict[y].remove(x)

            reachable_list = set()
            reachable_list.add(0)
            temp = 0
            while True:
                for node in edge_out_dict:
                    if node in reachable_list:
                        reachable_list.update(edge_out_dict[node])

                if len(reachable_list) == temp:
                    break
                temp = len(reachable_list)
        else:
            x,y = a[t].split('->')
            x,y = int(x),int(y)
            edge_out_dict[x].append(y)
            edge_in_dict[y].append(x)
            node_set.add(x)
            node_set.add(y)

            temp = 0
            while True:
                for node in edge_out_dict:
                    if node in reachable_list:
                        # if 0 in edge_out_dict[node] and reach_flag == 0:
                        #     print('cycle!',t)
                        #     reach_flag = 1
                        reachable_list.update(edge_out_dict[node])
                if len(reachable_list) == temp:
                    break
                temp = len(reachable_list)

        if len(node_set) >= 1000 and temp_1 < 1000:
            print('V over 1000!',t,temp_1,len(node_set))
        temp_1 = len(node_set)

        if len(reachable_list) >= 1000 and temp_2 < 1000:
            print('R over 1000!',t,temp_2,len(reachable_list))
        temp_2 = len(reachable_list)

    num = 0
    for node in edge_out_dict:
        num += len(edge_out_dict[node])
    print(num)
    print(len(node_set),len(reachable_list))
    max_in = 0
    max_in_node = 0
    max_out = 0
    max_out_node = 0
    for node in edge_out_dict:
        if len(edge_out_dict[node]) > max_out:
            max_out_node = node
            max_out = len(edge_out_dict[node])

    for node in edge_in_dict:
        if len(edge_in_dict[node]) > max_in:
            max_in_node = node
            max_in = len(edge_in_dict[node])
    print('max_out',max_out_node,max_out)
    print('max_in',max_in_node,max_in)

def kadai3(num):

    def show(number,show_list):
        args = []
        for node,edge in edge_out_dict.items():
            if number in edge:
                print(node,edge,number)
                if not node in show_list:
                    args.append(node)
                    show_list.append(node)

        if len(args) > 0:
            for arg in args:
                show(arg,show_list)
        return

    with open('c.txt') as f:
        a = f.read().split('\n')
    node_set = set()
    edge_out_dict = defaultdict(list)
    edge_in_dict = defaultdict(list)
    reachable_list = set()
    reachable_list.add(0)
    temp_1 = 0
    temp_2 = 0
    reach_flag = 0

    for t in range(len(a)):
        print(t,a[t])
        # if str(num) in a[t]:
        #     print(t,a[t])
        if '!' in a[t]:
            x,y = a[t][1:].split('->')
            x,y = int(x),int(y)
            # if x == num or y == num:
            #     print(t,a[t])
            try:
                edge_out_dict[x].remove(y)
            except:
                print('******************************************')
            # edge_in_dict[y].remove(x)
            temp = 0
            reachable_list = set()
            reachable_list.add(0)
            while True:
                for node in edge_out_dict:
                    if node in reachable_list:
                        reachable_list.update(edge_out_dict[node])

                if len(reachable_list) == temp:
                    break
                temp = len(reachable_list)

        else:
            x,y = a[t].split('->')
            x,y = int(x),int(y)
            # if x == num or y == num:
            #     print(t,a[t])
            edge_out_dict[x].append(y)
            # edge_in_dict[y].append(x)
            temp = 0
            reachable_list = set()
            reachable_list.add(0)
            while True:
                for node in edge_out_dict:
                    if node in reachable_list:
                        reachable_list.update(edge_out_dict[node])
                if len(reachable_list) == temp:
                    break
                temp = len(reachable_list)

        node_list = []
        for node in edge_out_dict:
            node_list.append(node)

        for node in node_list:
            if not node in reachable_list:
                edge_out_dict.pop(node)
            else:
                for edge in edge_out_dict[node]:
                    if not edge in reachable_list:
                        edge_out_dict[node].remove(edge)



        # new_edge_out_dict = defaultdict(list)
        # for node in reachable_list:
        #     for edge in edge_out_dict[node]:
        #         if edge in reachable_list:
        #             new_edge_out_dict[node].append(edge)
        # edge_out_dict = copy.deepcopy(new_edge_out_dict)



        # show(num)
        # pp.pprint(sorted(edge_out_dict.items(), key=lambda x: x[0]))
        # print(sorted(reachable_list))
        # print('--------------------------------------------------')
        # time.sleep(2)

    A = 0
    for node in edge_out_dict:
        A += len(edge_out_dict[node])
    print(len(node_set),len(reachable_list),A)



if __name__ == '__main__':
    import sys
    # num = int(sys.argv[1])
    num = 0
    # kadai1()
    kadai2()
    # kadai3(num)
    #1116
    #8624