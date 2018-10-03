
import time,math

def fib(n):
    if n == 1 or n == 0:
        return 1
    else:
        return fib(n-1) + fib(n-2)

def fib_dp(n):

    if n == 1 or n==0:
        return 1
    temp_1 = 1
    temp_2 = 1
    num = 0
    for i in range(n-1):
        num = temp_1 + temp_2
        temp_2 = temp_1
        temp_1 = num
    return num


def kadai1():
    print(fib(10))

def kadai24():
    s = time.time()
    print(fib_dp(140))
    print(1234567890123456789012345678901234567890)
    print(time.time()-s)

def kadai3():
    with open('num.txt') as f:
        a,b = f.read().split('\n')
    c = int(a) + int(b)
    print(c)

def kadai5():
    with open('num_2.txt') as f:
        a,b = (map(lambda x:x.split(' '),f.read().split('\n')))
    x = float( a[0][0] + '.' + a[0][1:]) * 10**int(a[1])
    y = float( b[0][0] + '.' + b[0][1:]) * 10**int(b[1])
    print(int(a[0]))
    print(x)
    print(y)
    print()
    z = x * y
    print(z)
    w = str(int(a[0]) * int(b[0]))
    print(w[:32],len(w)-1+int(a[1])-31+int(b[1])-31) #* 10 **(int(a[1])-31 + int(b[1]) - 31))

def kadai6():
    phi = (1 + math.sqrt(5)) * 10
    print(phi)
if __name__ == '__main__':
    # kadai1()
    # kadai24()
    # kadai3()
    # kadai5()
    kadai6()