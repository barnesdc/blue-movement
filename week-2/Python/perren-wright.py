def longestpalindrome(s):
    if (s == ''):
        return None
    fwdlist = list(s)
    revlist = fwdlist[::-1]
    if(fwdlist == revlist):  
        return ''.join(fwdlist) 
    else:
        for i in range(0, len(fwdlist)):
            if(fwdlist != revlist):
                fwdlist.pop()
                revlist.pop(0)
            else:
                return ''.join(fwdlist)
    return None



def main():
    assert longestpalindrome("ababad") == "ababa", "Base Case"

if __name__ == "__main__":
    main()