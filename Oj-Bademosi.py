#Problem 2
from collections import Counter

#accept the number of integers

n = int(input())

#accept the integers , this will create  list of the input values

a = list(map(int,input().split()))

#acepst the value of k

k = int(input())

#this will create a frequenct distribution dictionary

#key will be the values and value will be the number of times they occur

c = Counter(a)

ans_list = []

#now iterate over this collectiosn and findall which ahve k as the frequency

for  i in c.items():

    # if frequency is same as k append it to list

    if i[1]==k:

        ans_list.append(i[0])

#finally print the min value in list

print(min(ans_list))
