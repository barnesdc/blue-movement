#Meron Solomon
from itertools import permutations

#this function prints out the permutation from string input
def printPermutation(My_String):
    lst=[]
    Hold_perm = permutations(My_String)#useing the Permutation library
    for i in list(Hold_perm):#loop will go through the size of the string until it finishes plugginf in the permutation
        hold_prem_2=(''.join(i))
        lst.append(hold_prem_2)
    print("\nOutput:\n")
    print(lst)#printing out the permutation

#this function takes in a string and 
def Palindrome_Machine(My_String):
    #this if statement checks the string
	if not My_String: 
            return My_String
	String_length, a, b = len(My_String), 0, 0
    #
	String_Hold = [[True]*String_length, [False]*String_length]   
    #This loop goes through the given string and appends it
	for c in range(String_length-1):
		if My_String[c] == My_String[c+1]:
			String_Hold[1][c] = True
			a, b = c, c+1    
    #This loop takes in the string and converts it into the permuatation                   
	for d in range(2, String_length):         
		for c in range(String_length-d):
			Hold_return = c+d
			y, z = d%2, c+d//2
			String_Hold[y][z] = String_Hold[y][z] and My_String[c] == My_String[Hold_return]
			if String_Hold[y][z] and Hold_return-c > b-a:
				a, b = c, Hold_return
	return My_String[a:b+1]


# this while loop runs endlessely until you press the number 3 
#Enter 1 to turn string into Palindrome
#Enter 2 for string permutation
#First enter a number then you enter a string that you want to turn into a palindrome or permutations
while True:
    i=input("\nEnter 1 to turn string into Palindrome\nEnter 2 for string permutation\n3 to exit\n")
    i=int(i)
    if i==1:
        String_1 = input("\nEnter String-Palindrome\n")
        print("\nOutput:\n")
        print(Palindrome_Machine(String_1))

    elif i==2:
        String_2 = input("\nEnter String-Permutation\n")
        printPermutation(String_2)

    elif i==3:
        break
    else:
        print("\nwrong")

