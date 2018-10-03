import time, threading

class Hoge():

    def __init__(self):
        self.stop_event = threading.Event() #停止させるかのフラグ
        self.inc_event = threading.Event()  #刻み幅を増やすかのフラグ

        #スレッドの作成と開始
        self.thread = threading.Thread(target = self.target)
        self.thread.start()

    def target(self):
        """ひたすら 'count 数字' と出力する"""
        count = 1
        step = 1
        while not self.stop_event.is_set():
            time.sleep(1)
            print ("count %d" % count)

            if self.inc_event.is_set():
                step += 1
                self.inc_event.clear()
            count += step

    def stop(self):
        """スレッドを停止させる"""
        self.stop_event.set()
        self.thread.join()    #スレッドが停止するのを待つ

    def inc(self):
        """targetで出力する数字の刻み幅を増やすフラグを立てる"""
        self.inc_event.set()

if __name__ == '__main__':
    h = Hoge()      #スレッドの開始
    time.sleep(3)   
    h.inc()         #countの刻み幅を2に
    time.sleep(3)
    h.stop()        #スレッドの停止
    time.sleep(3)   #メインスレッドが終わる前に止まってる！
    print ("finish")