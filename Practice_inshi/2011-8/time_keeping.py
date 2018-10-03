import threading
from Queue import Queue
import time

RUNNING_TIME_IN_SEC = 60

queue = None

class Runner(object):

    def __init__(self):
        self.startTime = time.time()

    def isRunning(self):
        return time.time() - self.startTime < RUNNING_TIME_IN_SEC

def timeKeeper(runEvent):
    runner = Runner()
    while runEvent.is_set() and runner.isRunning():
        time.sleep(1)
    print ("timeKeeper: finished")
    queue.put("finished")

def timedOutput(runEvent):
    while runEvent.is_set():
        time.sleep(2)
        print (time.time())

if __name__ == "__main__":
    queue = Queue()
    runEvent = threading.Event()
    runEvent.set()
    t1 = threading.Thread(target = timeKeeper, args = (runEvent,))
    t2 = threading.Thread(target = timedOutput, args = (runEvent,))
    t1.start()
    t2.start()

    try:
        while True:
            time.sleep(1.0)
            if not queue.empty():
                print ("queue not empty")
                if queue.get_nowait() == "finished":
                    print ("recieved 'finished'")
                    break
    except KeyboardInterrupt:
        print ("attempting to close threads.")
    runEvent.clear()
    t1.join()
    t2.join()
    print ("threads successfully closed")