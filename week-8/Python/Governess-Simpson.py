'''
# Sample code to perform I/O:

name = raw_input()          # Reading input from STDIN
print 'Hi, %s.' % name      # Writing output to STDOUT

# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''

#Prompt 1: Stone's Love
'''Senorita likes stones very much. As she is fond of collecting beautiful stones, everyday she finds some of 
the stones beautiful and collects it in her bottle.

You are given the number of stones, she collects each day for N numbers of days, starting from the very first day. 
Now you are given Q queries, in each query her friend shambhavi asks you the number of days she has taken to collect
M number of stones. Please note that each query contains the different number of M.
'''

# bisect: good for binary searching as it
# keeps the list in sorted order while inserting values.
# found through example problem/documentation in Python

from bisect import bisect_left as bl

# defines the function and the values (grabbed as inputs)
# working as iterators
N, Q = map(int,raw_input().split())

storage = []

for i in map(int,raw_input().split()):
    if len(storage)==0:
        storage.append(i)
    else:
        storage.append(i + storage[-1])

M = map(int,raw_input().split())

# Iterates through the array with bl more efficiently
for m in M[0 : Q]:
    print bl(storage, m) + 1
        
        
#Prompt 2: Repeated K Times
'''Given a List of N number a1,a2,a3........an, You have to find smallest number from the 
List that is repeated in the List exactly K number of times.
'''

# maps the occurrences of the values in an array
# and creates a dictionary of it - just a simpler way
# of making a dictionary
from collections import Counter

N = (raw_input())

# list comprehension to store values from the input (separated)
a = [int(i) for i in raw_input().split()]

# changes string value of k to integers that can be
# manipulated
k = int(raw_input())

a.sort()
d = Counter(a)

# if the values in d equal k, that means the value occurs
# "k" times.
for i in d.keys():
    if d[i]==k:
        print(i)
        break
