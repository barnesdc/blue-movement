
 class Asignment  {
  private static  boolean isPalindrome(String str){
    return str.equals(new StringBuilder(str).reverse().toString());
  }
  
  
public static String  longestPalindromesub(String s){


  for(int i=0;i<s.length();i++){

    for(int j=s.length()-1;j>i;j--){
      String sub=s.substring(i,j);
      if(isPalindrome(sub)){
return sub;
      }
    }
  }
return " ";
}



private static String Swap(String s, int i, int j){
   char[] b =s.toCharArray();  
        char ch;  
        ch = b[i];  
        b[i] = b[j];  
        b[j] = ch;  
        return String.valueOf(b);  
}

private static void Permutate(String s, int start, int end)  
    {  
        if (start == end-1)  
            System.out.format("%s  ",s);  
        else  
        {  
            for (int i = start; i < end; i++)  
            {  
                  
                s = Swap(s,start,i);  
                Permutate(s,start+1,end);   
                s= Swap(s,start,i);  
            }  
        }  
    } 

    
public static void printPermutations(String s){
  Permutate(s,0,s.length());
  System.out.println();
}
  }
  