
def finalPrice(prices):
    total = 0
    indexArray = []
    for i in range(0,len(prices)):
        temp = prices[i]
        for j in range(i+1,len(prices)):
            if prices[i] >= prices[j]:
                temp = prices[i] - prices[j]
                break
        if temp == prices[i]:
            indexArray.append(i)
        total = total + temp
    print(total)
    for i in range(0,len(indexArray)):
        print(indexArray[i],end = ' ')



    # 7/14 passed - time out

    #!/bin/python3
"""
import math
import os
import random
import re
import sys



#
# Complete the 'applyOperations' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY arr as parameter.
#
# try to reverse the queue and pop it onto stack
# try using a deqeue -- theres a pattern in which things are added
#
def applyOperations(arr):
    # Write your code here
    stack = []
    queue = []
    arrLen = len(arr)

    i = 0
    while i < arrLen:
        # step one: pop from stack, push to queue
        while len(stack) != 0:
            tempS = stack.pop(0)
            queue.append(tempS)
        # step two: add array element to stack
        stack.insert(0,arr[i])
        # step three: pop from queue, push to stack
        while len(queue) != 0:
            tempQ = queue.pop(0)
            stack.insert(0,tempQ)
        i = i + 1
    return stack
"""