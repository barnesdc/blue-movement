def stone_love(N,Q): # N:list of stones collected each day   Q: list      of queries
    for x in Q:
        days = 0
        ind = 0
        while x> 0:
                x -= N[ind]
                ind += 1
                days += 1

        print(days)



def repeated_ktimes(num, k):
  num.sort()
  for x in num:
    if num.count(x) == k:
      return x

if __name__ == "__main__":
    n = [1,2,4,6,7,3,2,5,0,6]
    q = [5,10,3,8,31]

    stone_love(n,q)
    

    a = repeated_ktimes([1,2,6,6,8,5,6,1,1,4],3)
    assert a == 1

    a = repeated_ktimes([1,2,6,7,8, 8,5,6,5,4],2)
    assert a = 5
