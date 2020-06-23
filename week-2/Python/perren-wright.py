import math
def longestpalindrome(s):
    if (s == ''):
        return None
    fwdlist = list(s)
    revlist = fwdlist[::-1]
    fwdlist1 = list(s)
    revlist1 = fwdlist1[::-1]
    fwdlist2 = list(s)
    revlist2 = fwdlist2[::-1]
    longstr = ""
    if(fwdlist == revlist):
        longstr = ''.join(fwdlist) 
        return longstr 
    else:
        for i in range(0, len(fwdlist)):
            if(len(fwdlist) == 2):
                return longstr
            if(fwdlist == revlist):
                if(len(''.join(fwdlist)) > len(longstr)):
                    longstr = ''.join(fwdlist) 
            elif(fwdlist1 == revlist1):
                if(len(''.join(fwdlist1)) > len(longstr)):
                    longstr = ''.join(fwdlist1)
            elif(fwdlist2 == revlist2):
                if(len(''.join(fwdlist2)) > len(longstr)):
                    longstr = ''.join(fwdlist2)
            else:
                fwdlist.pop()
                revlist.pop(0)
                fwdlist1.pop(0)
                revlist1.pop()
                if(len(fwdlist2) > 2):
                    fwdlist2.pop(0)
                    fwdlist2.pop()
                    revlist2.pop(0)
                    revlist2.pop() 
    print(longstr)     
    return longstr

def allpermutations(str):
    allperm = ""
    strlst = list(str)
    allperm += str + " "
    totlist = permutation(strlst)
    #adds words together
    allperm += ''.join(totlist)
    return allperm
        
def permutation(strlst):
    output = []
    i = len(strlst) - 1
    j = len(strlst) - 1
    v = math.factorial(len(strlst))  
    for k in range(0, v - 1):
        if((k == math.factorial(len(strlst) / len(strlst))) and len(strlst) > 3):
            tlst = strlst[1:len(strlst)-2:-1]
            tlst.insert(0, strlst[0])
            strlst = tlst
            output.extend(strlst)
            output.append(" ")
            j = len(strlst) - 1        
        elif(k % 2 == 0):
            swaplst = swap(strlst, i-1, i)
            output.extend(swaplst)
            output.append(" ")
            strlst = swaplst
        elif(k % 2 != 0):
            templst = swaplst[j:]
            templst1 = swaplst[:j]
            templst.extend(templst1)
            j = j - 1
            output.extend(templst)
            output.append(" ")
            strlst = templst
    return output    


def swap(swaplst, idx1, idx2):
    swaplst[idx1], swaplst[idx2] = swaplst[idx2], swaplst[idx1]
    return swaplst

print(allpermutations("abc"))




def main():
    assert longestpalindrome("ababad") == "ababa", "Base Case"
    assert longestpalindrome("ab") == "", "Not palindrome"
    assert longestpalindrome("bb") == "bb", "Double small"
    assert longestpalindrome("bavava") == "avava", "Reverse at Front"
    assert longestpalindrome("bavavac") == "avava", "Both ends"

if __name__ == "__main__":
    main()