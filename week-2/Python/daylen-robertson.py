"""
1. Given a string, find the longest substring 
which is palindrome. For example, if the given 
string is "ababad", the output should be "ababa".
"""
"""First thing is to anaylze the problem.
Since it's a palindrome, we know if its backwards
it will be the same forward. So we reverse the string
with the [start:stop:step] index slice parameters
and then compare it to itself and see if it's the same.

In this case I used the [::-1] parameters 
so I can start at the VERY beginning and the VERY end
when reversing. If you dont do this you wont be slicing
the whole list since the STOP parameter is where you will
stop and it wont be counted."""

"""string is what we will be taking in so we can have
any test case. palinSave will be the biggest palindrome"""


"""The double for loop allows us to start at the beginning,
check the whole length, and go to the next index and check
the whole length again. My 2nd loop range has a 
(len(string),0,-1) in order to reverse it using -1 
as a reverse step. Going reverse made more sense to me conceptually"""


def palin():
    string=input("Add a string: ")
    if len(string)==1 or string=="":
        return string
    #saves first index so if no palindrome this would pass
    palinSave=string[0]

    #init
    start=0
    counter=len(string)

    while start< len(string):
    #for letter in range(0,len(string))
    #for endletter in range(len(string),0,-1)
            palinCheck=string[start:counter]
            palinCompare=palinCheck[::-1]
            if palinCheck==palinCompare:
            #Now that we found one, check if its the longest 
                if len(palinCheck)>len(palinSave):
                    palinSave=palinCheck
            if counter!=start:
                counter-=1
            else:
                counter=len(string)
                start+=1
            
    return palinSave
result= palin()
print(result)
"""
2. Given a string str, the task is to print all the 
permutations of str. A permutation is an 
arrangement of all or part of a set of objects, 
with regard to the order of the arrangement. 
For example, if given "abb", the output should be 
"abb abb bab bba bab bba"
"""
def perms():
    from itertools import permutations
    string=input()
    allperms= list(permutations(string))

    #Creates a structure with no duplicates
    set_of_all_perms=set(allperms)

    for i in allperms:
        i="".join(i)
        print(i)

"""I just used python's permutations module from the
itertools library because I felt like there wasnt a point
in reinventing the wheel. But, here's what I'd do if I
didnt use the module:
Basically, I'd use shuffle to create the perms but I
wont add them unless they arent in the list. 

I'd use the factorial length of the string as my length.
If there are duplicates, Ill cut the size down in half
This runtime is terrible and I prefer my above solution:
"""
def secondSolution (string):
    import random

    total=1
    for num in range(len(string)+1):
        if num==0:
            continue
        else:
            total*=num

    dupliCheck=dict.fromkeys(string)
    if len(string)!=len(dupliCheck) :
        total/=2

    string= list(string)


    perms=[]
    random.shuffle(string)
    grabber="".join(string)
    print(grabber)
    perms.append(grabber)

    while len(perms)<total:
        random.shuffle(string)
        grabber="".join(string)
        if grabber in perms:
            pass
        else:
            perms.append(grabber)
            print(perms)

    print(len(perms))

    #Way more work :/