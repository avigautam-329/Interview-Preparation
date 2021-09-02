from threading import Thread, Semaphore
import time

# creating semaphore instance to define the number of threads that can run at once.
obj = Semaphore(3)

def display(name):

    # THis is where the thread acquire's the lock and the value of semaphore will decrease by 1.
    obj.acquire()
    for i in range(3):
        print("Hello from {}".format(name))
        time.sleep(1)

    obj.release()


t1 = Thread(target = display, args = ("Thread 1",))
t2 = Thread(target = display, args = ("Thread 2",))
t3 = Thread(target = display, args = ("Thread 3",))
t4 = Thread(target = display, args = ("Thread 4",))
t5 = Thread(target = display, args = ("Thread 5",))
t6 = Thread(target = display, args = ("Thread 6",))

t1.start()
t2.start()
t3.start()
t4.start()
t5.start()
t6.start()

# join() is not needed as we are not making a main function
