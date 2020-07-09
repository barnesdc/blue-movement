def longestPalindrome(string):
    ## Lets do this w/ brute force
    maxPalLen = -1
    for startInd in range(len(string)):
        for stopInd in range(startInd+1, len(string)+1):
            if string[startInd:stopInd] == string[startInd:stopInd][::-1] and stopInd-startInd > maxPalLen:
                maxPalLen = stopInd-startInd
    return maxPalLen
    

def allPermutations(string):
    from itertools import permutations
    listPerm = [perm for perm in permutations(string)]
    strPerm = [('').join(perm) for perm in listPerm]
    return strPerm
    
allPermutations('abb')

longestPalindrome('a')
    