from collections import deque


def sum_lists():
    #I dont know how we were supposed to input the #'s but 
    # I'd just use a standard iterative input loop until None
    ll1=deque([5,6,3])
    ll2=deque([8,4,2])

    #used to represent the tens place
    multi=1
    total=0
    #this makes multiplying easy since I can start at the
    #ones place
    ll1.reverse()
    for num in ll1:
        total+=num*multi
        multi*=10

    #Repeats the same process
    multi=1
    ll2.reverse()

    for num in ll2:
        total+=num*multi
        multi*=10
    print(total)

def words_reverse():
    s=deque(["I"," ","l","o","v","e"," ","g","e","e","k","s"," ","f","o","r"," ","g","e","e","k","s"])
    templist=""
    #check to see if it's one word
    if " " not in s:
        print(s)
    else:
        #copy deque using a string, then split by spaces
        for i in s:
            templist+=i
        templist=templist.split(" ")

        #return split version to s, then reverse it
        s=deque(templist)
        s.reverse()
        print(s)

