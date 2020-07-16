#prompt 1
def isPalindrome(str,length):
  split = length//2

  if (length%2 == 0):
    a = str[:split]
    b = str[split+1//2:]
    rev_b = b[::-1]

  else:
    a = str[:split]
    b = str[split + 1:]
    rev_b = b[::-1]


  if (a == rev_b):
    return True
  else:
    return False


def palindrome(str):
    string = ""
    for i in range(len(str)):
        occ = str.count(str[i],i) - 1
        start = str.find(str[i])
        end = str.find(str[i],start+1)

        while (occ > 0 ):
            sub = str[start:end+1]
            length = end - start + 1

            pal = isPalindrome(sub,length)

            if ( pal and length > len(string)):
                string = sub

            end = str.find(str[i],end+1)

            occ -= 1

    print(string)



# prompt 2
def perm_helper(list_str,first,last):
  if (first == last):
      end_str = ''.join(list_str)
      print(end_str)

  else:
      for i in range(first,last+1):
        list_str[i], list_str[first] = list_str[first], list_str[i]
        perm_helper(list_str,first+1,last)
        list_str[first], list_str[i] = list_str[i], list_str[first]

def permuted(str):
    list_str = list(str)
    print()

    length = len(list_str)

    perm_helper(list_str,0,length-1)
