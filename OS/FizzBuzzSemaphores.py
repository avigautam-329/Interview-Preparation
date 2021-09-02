from threading import Thread, Semaphore

class FizzBuzz(object):
    def __init__(self, n):
        self.n = n
        self.count = 1
        self.cv = Semaphore(4)


    def fizz(self):
        if self.count <= self.n:
            self.cv.acquire()
            if self.count % 3 == 0 and self.count % 5 != 0:
                print("fizz")
                self.count += 1
            self.cv.release()

    def buzz(self):
        if self.count <= self.n:
            self.cv.acquire()
            if self.count % 3 != 0 and self.count % 5 == 0:
                print("buzz")
                self.count += 1
            self.cv.release()

    def fizzbuzz(self):
        if self.count <= self.n:
            self.cv.acquire()
            if self.count % 3 == 0 and self.count % 5 == 0:
                print("fizzbuzz")
                self.count += 1
            self.cv.release()

    def number(self):
        if self.count <= self.n:
            self.cv.acquire()
            if self.count % 3 != 0 and self.count % 5 != 0:
                print("{}".format(self.count))
                self.count += 1
            self.cv.release()

obj = FizzBuzz(100)


for i in range(100):
    t1 = Thread(target = obj.fizz, args = ())
    t2 = Thread(target = obj.buzz, args = ())
    t3 = Thread(target = obj.fizzbuzz, args = ())
    t4 = Thread(target = obj.number, args = ())

    t1.start()
    t2.start()
    t3.start()
    t4.start()

    t1.join()
    t2.join()
    t3.join()
    t4.join()

