
public class Link_list
{ 
    class Take_n  
    { 
        int num; 
        Take_n next; 
  
        public Take_n(int num)  
        { 
            this.num = num; 
        } 
    } 
      

    void Release(Take_n top)  
    { 
        while (top != null)  
        { 
            System.out.print(top.num + " "); 
            top = top.next; 
        } 
    } 
  
    Take_n Rest_1, Rest_2, Final; 
    int Take_on; 
  
   
    void input_var(int num, int Test_Hold)  
    { 
        Take_n newnode = new Take_n(num); 
        if (Test_Hold == 1)  
        { 
            newnode.next = Rest_1; 
            Rest_1 = newnode; 
        }  
        else if (Test_Hold == 2)  
        { 
            newnode.next = Rest_2; 
            Rest_2 = newnode; 
        }  
        else 
        { 
            newnode.next = Final; 
            Final = newnode; 
        } 
  
    } 
  
    
    void compare_size(Take_n n, Take_n m)  
    { 
      
        if (n == null) 
            return; 
  
         
        compare_size(n.next, m.next); 
  
       
        int sum = n.num + m.num + Take_on; 
        Take_on = sum / 10; 
        sum = sum % 10; 
  
         
        input_var(sum, 3); 
  
    } 
  
    Take_n which_one; 
  
   
    void take_on_C(Take_n Rest_1)  
    { 

        if (Rest_1 != which_one)  
        { 
            take_on_C(Rest_1.next); 
            int sum = Take_on + Rest_1.num; 
            Take_on = sum / 10; 
            sum %= 10; 
  

            input_var(sum, 3); 
        } 
    } 
  
    int take_on(Take_n top)  
    { 
        int count = 0; 
        while (top != null)  
        { 
            count++; 
            top = top.next; 
        } 
        return count; 
    } 
  

    void add_on_there()  
    { 

        if (Rest_1 == null)  
        { 
            Final = Rest_2; 
            return; 
        } 
  

        if (Rest_2 == null)  
        { 
            Final = Rest_1; 
            return; 
        } 
  
        int size1 = take_on(Rest_1); 
        int size2 = take_on(Rest_2); 
  

        if (size1 == size2)  
        { 
            compare_size(Rest_1, Rest_2); 
        }  
        else 
        { 

            if (size1 < size2)  
            { 
                Take_n check = Rest_1; 
                Rest_1 = Rest_2; 
                Rest_2 = check; 
            } 
            int seperate = Math.abs(size1 - size2); 
  
        
            Take_n check = Rest_1; 
            while (seperate-- >= 0)  
            { 
                which_one = check; 
                check = check.next; 
            } 
  

            compare_size(which_one, Rest_2); 
  

            take_on_C(Rest_1); 
        } 
    
            if (Take_on > 0) 
                input_var(Take_on, 3); 
          
    } 
  

    public static void main(String args[]) 
    { 
    	Link_list Test_Hold = new Link_list(); 
        Test_Hold.Rest_1 = null; 
        Test_Hold.Rest_2 = null; 
        Test_Hold.Final = null; 
        Test_Hold.Take_on = 0; 
        int Case_1[] = { 5, 6, 3 }; 
        int Case_2[] = { 8, 4, 2 }; 
  
       
        for (int i = Case_1.length - 1; i >= 0; --i) 
            Test_Hold.input_var(Case_1[i], 1); 
  
    
        for (int i = Case_2.length - 1; i >= 0; --i) 
            Test_Hold.input_var(Case_2[i], 2); 
  
        Test_Hold.add_on_there(); 
  
        Test_Hold.Release(Test_Hold.Final); 
    } 
} 