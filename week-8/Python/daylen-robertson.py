
def stone_love():
    from bisect import bisect_left
    #On hacker earth the first test case is incorrect bc their output doesn't make sense with the input.
    #I could be wrong though, if so, I have code that will run for that too, just a simple nested for loop
    #The loop uses a dictionary with # stone keys and day values and checks if the value is >= Q
    #That was time inefficient though
    num=input().split()
    n=int(num[0])
    qq=int(num[1])
    numStone=input().split()
    qStones=input().split()



    total=0
    array=[]
    for j in numStone:
        total+=int(j)
        array.append(total)

    for q in qStones:
        print(bisect_left(array,int(q))+1)


def repeated_k_times():
    n=int(input())
    array=input().split()
    array.sort()
    arrayset=set(array)
    arrayset=sorted(arrayset)
    dic=dict.fromkeys(arrayset)


    k=int(input())

    #sets values to 0
    for i in dic:
        dic[i]=0

    #When it equals k, print #
    for i in array:
        dic[i]+=1
        if int(dic[i])==k:
            print (i)
            break