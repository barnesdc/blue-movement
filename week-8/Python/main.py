#Prompt 1 (Stone's Love)
import bisect
# Write your code here

first = input()
N = input()
N = N.split()
Q = input()
Q = Q.split()
arr = []
total = 0

for i in N:
    if i != ' ':
        total += int(i)
        arr.append(total)

for j in range(0,len(Q)): 
    print((bisect.bisect_left(arr, int(Q[j]))+1))
            
# Prompt 2 (Repeated K times)
# N = int(input())
# arr = input()
# arr = arr.split()
# b = sorted(set(arr))
# k = int(input())

#for i in b:
#    if arr.count(i) == k:
#        print(i)
#        break
