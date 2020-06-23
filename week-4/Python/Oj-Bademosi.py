
# Define Node class and linked list class 
# Node class 
class Node: 

        def __init__(self, data):    # Constructor 
                self.data = data         # Value
                self.next = None         # next node  

#Linked List list class
class LinkedList: 

    def __init__(self): 
        self.head = None        # initializes head node

                
    # Function to insert a new node at the end of the list
    def append(self, new_value): 
        
        new_node = Node(new_value)    # Create a new node with the data passed
        # Check The linked list is empty or not, if empty, head of the list will be none, if so, make the new_node the head and return
        if self.head is None:  
            self.head = new_node
            return
        
        # Traversed till the end of the list , from head , (Last nodes next will be none)
        tmp = self.head
        while tmp.next is not None:
            tmp = tmp.next
        
        # Add the new node to the next of tmp
        tmp.next = new_node

    # Utility function to print the LinkedList 
    # Prints the list in a->b->c->d->NULL format
    def print_list(self): 
        temp = self.head 
        while(temp): 
            print (temp.data+"->", end="") 
            temp = temp.next
        print("NULL")


    # Utility function to print the LinkedList as string 
    # Prints the list as srting
    def print_srting(self): 
        temp = self.head 
        while(temp): 
            print (temp.data, end="") 
            temp = temp.next



    def reverse_sent(self):

        # if list is empty, return
        if self.head is None:  
            return
        
        # Create some temporary nodes
        word_sp = self.head          # To store the word start position while traversing (initially head).
        sent_end = Node(None)        # To store the end of the sentence
        sent_start = Node(None)      # To store the start position of the sentence

        # Traverse the list until a ' ' (<space>) or end (None) is found
        temp = self.head
        while temp is not None and temp.data != ' ':
            sent_end = temp
            temp = temp.next

        # After the above loop sent_end->next will be holding either first ' ' or None ( if only one word in sentence)

        if temp is None:
            # check if temp (which is the same as sent_end->next) is None , ie single word , if true return
            return


        # now that we have the first space  in temp,
        # Main loop
        while temp is not None:

            # store the value which is next to the current space to a temp value (beginning of the next word to be processed)
            tmp_next = temp.next

            #  this will swap the space with the beginning of the word processed
            temp.next = word_sp
            # and the new word start position is temp
            word_sp = temp 

            #initiallize a prev_node ( to be used in loop)
            prev = Node(None)

            # copy back the node from tmp_next 
            temp = tmp_next 

            # now that we have another word, this is the beginning of the sentence
            sent_start = temp

            # now again loop through for the next space or None
            while temp is not None and temp.data != ' ':
                prev = temp
                temp = temp.next

            # now prev.next becomes the next word start
            prev.next = word_sp
            # new word start becomes the beginning of the sentence (assigned before loop)
            word_sp = sent_start


        # out of the loop, now sent_start is the new head of the list
        self.head = sent_start        
        sent_end.next = None
   

