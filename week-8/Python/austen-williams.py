# Austen Williams
# Week 8 prompts 1 & 2
 
"""
1) Given Q queries find the number of days from Arr would it take to collect
   M number of stones
   
   Sample input    Sample Output
   5 4             2
   1 2 3 4 5       4
   3 8 10 14       4
                   5

2) Given a List of N number a1,a2,a3........an, You have to find smallest 
  number from the List that is repeated in the List exactly K number of times
  
  Sample input     Sample Output
  5                1
  2 2 1 3 1
  2
"""



def loveStones(arr, q):
    'finds the amount of days it will take to collect q[i] num of stones'
    for position, element in enumerate(q):
        days = 0
        count = 0
        i = 0
        while count < element and i < len(arr):
            count += arr[i]
            days += 1   
            i += 1
        if count >= element:            
            print(days)
        else:
            print('nothing ' + str(days))
 
 


def repeat(arr, k):
    'finds the smallest number in list repeated k times'
    arr.sort()
    for position, element in enumerate(arr):
        temp = position +1
        count = 1
        while temp < len(arr) and arr[temp] == element:
            count += 1
            if count == k:
                print(element)
                return
            temp += 1
            
            
if __name__ == '__main__':
    
    def testLoveStone():
        'used to test functionality of loveStone function'
        arr = [1,2,3,4,5]
        q = [3,8,10,14]
        loveStones(arr, q)
        
        
    def testLoveStone2():
        'used to test functionality of loveStone function'
        arr2 = [40, 31, 39, 7, 27, 10, 15, 22, 2, 25, 41, 44, 29, 32, 45, 10, 38, 36, 6, 1]
        q2 = [20, 418, 439, 251, 363, 331, 101, 328, 49, 460, 244, 390, 142, 384, 47, 470, 295, 263, 343, 97]
        loveStones(arr2, q2)
        
    def testRepeat():
        'used to test functionality of repeat function'
        arr = [2,2,1,3,1]
        k = 2
        repeat(arr, k)
    
    #testLoveStone()
    #testLoveStone2()
    #testRepeat()
    
    





