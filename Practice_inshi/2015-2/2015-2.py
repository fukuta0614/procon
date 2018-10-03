
from collections import defaultdict


# with open('') as f:
#     txt = f.read().split('\n')[:-1]

def func(n):
    if n < 1:
        return 1
    else:
        return (161 * func(n-1) + 2457) % (2 ** 24)

def func_ex(n):
    temp = 0
    for i in range(n+1):
        if i == 0:
            temp = 1
        else:
            temp = (161 * temp + 2457) % (2 ** 24)

    return temp

def g_func(n):
    temp = 0
    for i in range(n+1):
        if i == 0:
            temp = 1
        else:
            temp = (1103515245 * temp + 12345) % (2 ** 26)
    return temp

def kadai1():
    print(func(100))

def kadai2():
    count = 0
    for i in range(100):
        if func(i) % 2 == 0:
            print(i)
            count += 1
    print(count)

def kadai3():
    count = 0
    for i in range(100):
        if func(i) % 2 == 0 and i % 2 == 1:
            count += 1
    print(count)

def kadai4():
    print(func_ex(1000000))

def kadai5():
    print(g_func(2))
    print(g_func(3))

def kadai6():
    temp = 1
    i = 0
    while True:
        i += 1
        temp = (1103515245 * temp + 12345) % (2 ** 26)
        if i % 100000 == 0:
            print(i, temp)
        if temp == 1:
            print(i,temp)
            break

def kadai7():
    temp = 1
    h = 0
    i = 0
    while True:
        i += 1
        temp = (1103515245 * temp + 12345) % (2 ** 26)
        h = temp % (2**10)

        if i % 100000 == 0:
            print(i, temp)
        if h == 1:
            print(i,temp,h)
            break

if __name__ == '__main__':
    import time
    # kadai1()
    # kadai2()
    # kadai3()
    # kadai4()
    # kadai5()
    # kadai6()
    kadai7()