
import threading, queue
import collections

def applyOperation(arr):

    #creating empty stack and queues

    stack = []
    queue = collections.deque()

    #looping through while stack isn't empty

    for x in arr:
        while len(stack) != 0:
            # appending the last element of stack into queue(FIFO)
            queue.append(stack.pop())
        stack.append(x)

        # pushing items of queue into stack

        while len(queue) != 0:
            #from left side of queue(left end of deque)
            stack.append(queue.popleft())
    
    return list(stack[::-1])

arr = [1,3,2,4]
print("initial list: ", arr) 
print("After: ", applyOperation(arr))
