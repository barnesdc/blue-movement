#Stone's Love

# Input Processing

firstLineStr = input()
N,Q = firstLineStr.split(' ')
N = int(N)
Q = int(Q)

M = input()
M = M.split(' ')


Q = input()
Q = Q.split(' ')
print(Q)

# Array of total rocks collected per day
totalRocks = [0]
print(len(M))
for i in range(0,len(M)):
    totalRocks.append(int(int(M[i]) + totalRocks[i]))

# binary Search to find Day
def findDay(minDay,maxDay,query):
    guess = (minDay + maxDay) // 2
    #print('G = %d | Q = %d | Max = %d | Min = %d'%(guess,query,maxDay,minDay))
    if query > totalRocks[guess]:
        minDay = guess + 1
        findDay(minDay,maxDay,query)   
    elif (query < totalRocks[guess]):
        if (query > totalRocks[guess - 1]):
            print(guess)
        else:
            maxDay = guess - 1 
            findDay(minDay,maxDay,query)
    else:
        print(guess)
print(Q)
for i in range(0,len(Q)):
    print('here')
    findDay(0,N,int(Q[i]))






# Repeated K Times
""" 
This one is incomplete because I ran out of time

Idea:
create a set of all the values in the input array. Create another array that stores
The number of times that each value occurs in the input array. Use a binary search 
to figure out which input values occur K times within the input array
"""

from collections import Counter

# Handling input
N = input()
arr = input()
k = input()

arr = arr.split(' ')
arr.sort()
print(arr)
arrSet = list(set(arr))
arrSet.sort()
print(arrSet)

num = Counter(arr)

x = '1'
d = Counter(arr)
print(d[x])
