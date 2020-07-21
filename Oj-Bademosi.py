#OJ Bademosi
#Problem 1


#read N and Q
N, Q = map(int, input().split())
#read A[]
A = list(map(int, input().split()))
#read M
M = list(map(int, input().split()))[:Q]
A = [sum(A[0:x:1]) for x in range(0, len(A)+1)][1:]
for x in M:
for i in range(len(A)):
if A[i] >= x:
print(i+1)
break
else:
continue
