# Stack: LIFO 

def isEmpty(stk):
    if stk == []:
        return True
    else: 
        return False
def Push(stk, item):
    stk.append(item)
    top = len(stk) -1

def pop(stk):
    if isEmpty(stk):
        print("underflow")
    else: 
        item = stk.pop()
        if len(stk) == 0:
            top = None
        else: 
            top = len(stk)
            print("popped item is " +str(item))
        
def Display(stk):
    if isEmpty(stk): 
        print("stack is empty")
    else: 
        top = len(stk)-1
        print("elements in the stack are: ")
        for i in range(top, -1, -1):
            print(str(stk[i]))


#Adding elements to queue at the rear end
def enqueue(data):
   queue.insert(0,data)

#Removing the front element from the queue
def dequeue():
   if len(queue)>0:
      return queue.pop()
   return ("Queue Empty!")

#To display the elements of the queue
def display():
   print("Elements on queue are:");
   for i in range(len(queue)):
      print(queue[i])


# executable code
if __name__ == "__main__":
   stk=[]
   top=None
   Push(stk,1)
   Push(stk,2)
   Push(stk,3)
   Push(stk,4)
   pop(stk)
   Display(stk)
