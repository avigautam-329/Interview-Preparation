from threading import Condition, Thread
import time
import logging

logging.basicConfig(level = logging.DEBUG, format= '(%(threadName)-9s) %(message)s',)

#First we define the consumer function.

def consumer(cv):
    logging.debug('Consumer thread started ...')

    # This line is where the thread will acquire the lock.
    with cv:
        logging.debug('Consumer Waiting ...')

        # After executing this condition, the thread will release the lock and go to sleep.
        cv.wait()

        logging.debug('Consumer consumed the reseource.')

def producer(cv):
    logging.debug('Producer thread started...')

    with cv:
        logging.debug('Making resource available...')
        logging.debug('Notifying to all consumers...')
        cv.notify_all()


if __name__ == '__main__':
    condition = Condition();
    cs1 = Thread(name='consumer1', target= consumer, args=(condition,))
    cs2 = Thread(name='consumer2', target= consumer, args=(condition,))
    pd = Thread(name='producer', target=producer, args=(condition,))

    cs1.start()
    time.sleep(2)

    cs2.start()
    time.sleep(2)

    pd.start()
        
