import threading,time
from getch import getch

# lock object
import _thread

lck = _thread.allocate_lock()

def fadd() :
    global n
    global lck
    while 1:
        if lck.acquire() == 0 :
            pass
        else :
            n += 1
            lck.release()

def fdec() :
    global n
    global lck
    while 1:
        if lck.acquire() == 0 :
            pass
        else :
            n -= 1
            lck.release()

def func():
    global n
    while 1:
        time.sleep(1)
        print('\r'+n)
        if n=='a':
            return

# _thread.start_new_thread(fadd, ())
# _thread.start_new_thread(fdec, ())
# _thread.start_new_thread(func, ())
n = 'q'
t = threading.Thread(target=func,args=())
t.start()

while True:
    print('getch')
    n = getch()
    if n =='a':
        break