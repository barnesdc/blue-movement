# -*- coding: utf-8 -*-

"""
Week-2 prompts 1 and 2.

Prompts:
    
    
1)  Given a string, find the longest substring which is palindrome. 
For example, if the given string is "ababad", the output should be "ababa".


2)  Given a string str, the task is to print all the permutations of str. 
    A permutation is an arrangement of all or part of a set of objects, 
    with regard to the order of the arrangement. For example, if given "abb", 
    the output should be "abb abb bab bba bab bba"
    
    
    Longest Palindrome:
    Utilizes Manachers Algortihm that provides O(n) running time by using what
    is already known about the palindrome. As we traverese the palindrone we
    use a seperate array to store lengths of the palindrone at a given index.
    using this array we can predict the next best center  given the length of 
    previous palindromes. Since a palindrone cannot grow past a certain point
    to the left you can predict the next best center. For more information see:
    https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-1/
    
    Permutations:
    Used recursive aproach to perform swaps as the string becomes smaller and
    then stores all versions of permutations in a list of strings that it then 
    returns as a single string with all possible permutations.
    
"""

class Week2:
    
    
    
    def longestPalindrome(self, string):
        'function that returns the longest Palindrome using Manachers Algorithm'
        
        #if string is empty return string
        if len(string) == 0:
            return ""
        
        #modifiying string to always have odd palindrome
        stringMod = self.addHash(string) 
        
        #creating array to store the longest palindrone found
        lp = [0] * len(stringMod)
        
        lp[0]= 0
        lp[1] = 1
        
        #stores the center of the latest longest palindrome
        center = 1
        
        #stores the right most position of the latest palinndrome
        right_most_pos = 2
        
        #maximum length palindrome and center positon
        max_length = 1
        max_p_center = 1
        
        for index in range(2, len(stringMod)):
            # mirror of the current index center - index = index' - center
            mirror_of_index = (2*center) - index
            
            #checks if current index is within the right most position
            if right_most_pos - index > 0:
                lp[index] = min(lp[mirror_of_index], right_most_pos-index)
            
            #checks if the mirror of index is expanding past boundary of current longest palindrome
            if (index < right_most_pos):
                lp[index] = min(lp[mirror_of_index], right_most_pos - 1 )
            
            #sets rights and lefts of current palindrome around best center
            right_pos = (index + lp[index] + 1)
            left_pos = (index - lp[index] - 1)
           
            #expands the palindrone from center to check for palindrome
            while (right_pos < len(stringMod) and left_pos >=0 and 
                   stringMod[right_pos] == stringMod[left_pos]):
                lp[index] += 1
                right_pos += 1
                left_pos -= 1
            
            #checks if palindrone has exceded right most position and updates the new center
            if index + lp[index] > right_most_pos:
                center = index
                right_most_pos = index + lp[index]
            
            #checks if we have found a bigger palindrome than before
            if lp[index] > max_length:
                    max_length = lp[index]
                    max_p_center = index
        
        start = abs((max_p_center - max_length))
        end = max_p_center + max_length
        
        #returns largest found palidrome
        return self.removeHash(stringMod[start:end])
            
            
            
                
                
            
            
    def removeHash(self,string):
        'function to remove hashes as seperators for Longest Palindrome problem'
        new_string = ""
        for letter in string:
            if letter != '#':
                new_string += letter
        return new_string
        
    
   
    def addHash(self, string):
        'function to add hashes as seperators to ensure odd palindrome'
        newString = ""
        for i in string:
            newString += '#'
            newString += i
        newString += '#'
        return newString
    
        
        
    def permutation(self, string):
        'returns list of all permutations (represented as lists) of strings'
        if len(string) <= 1:
            return [string]
        pLst = []
        for i in range(len(string)):
            tmpLst = string[:i] + string[i+1:]  #swaps the values recursively
            for p in self.permutation(tmpLst):
                pLst.append(string[i] + p)
        return pLst
        
    
    def permutations(self, string):
        perms = self.permutation(string)
        new_string = ""
        for i in range(len(perms)-1):
            new_string += perms[i] + ' '
        new_string += perms[-1]
        return new_string
        
    
    
def palindroneTest(actual, palin):
    x = Week2()
    if actual != x.longestPalindrome(palin):
        print(f'Expected {actual} recieved {x.longestPalindrome(palin)}' )
    
def permutationsTest(actual, string):
    x = Week2()
    if actual != x.permutations(string):
        print(f'Expected {actual} recieved {x.permutations(string)}' )
    
    
    
    
    
    
    
if __name__ == "__main__":
    
    palindroneTest("ababa", "ababad")
    palindroneTest("willlliw", "austenwilllliwausten")
    palindroneTest("aba", "aabar")
    palindroneTest("abba", "abacdfgdcabba")
    palindroneTest("abacdedcaba","abacdedcaba")
    print("Palindrome test complete")
    
    permutationsTest("abb abb bab bba bab bba", "abb")
    
    print("Permutations test complete")
    
    
    
        