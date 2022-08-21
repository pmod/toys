import threading 

# difference lock vs rlock : https://superfastpython.com/thread-reentrant-lock/
lock = threading.RLock()

# bStart is added to guarantee all threads start acquiring lock when all started
# bEnd is added to guarantee all threads exist at the end of job to avoid its release by
# some thread's destruction
bStart = threading.Barrier(3)
bEnd = threading.Barrier(3)

def th(name):
    print( f"{name} thread started")

    bStart.wait()
    print( f"{name} thread activated")

    lock.acquire()
    ## some job
    #lock.release()

    print( f"{name} thread end")    
    bEnd.wait()

th1 = threading.Thread(target=th, args=(1,))
th2 = threading.Thread(target=th, args=(2,))
th3 = threading.Thread(target=th, args=(3,))

th1.start()
print( f"th1.is_alive={th1.is_alive()}, th2.is_alive={th2.is_alive()}, th3.is_alive={th3.is_alive()}")
th2.start()
print( f"th1.is_alive={th1.is_alive()}, th2.is_alive={th2.is_alive()}, th3.is_alive={th3.is_alive()}")
th3.start()
