
import java.util.LinkedList;

class LinkedListAsignment{


    /* 
    My thinkig for this fucntion it the process into sub functions.
    
    
    
    */
    public static LinkedList<Integer> SumList(LinkedList<Integer> first,LinkedList<Integer> second){
      int firstnum=NumberFromList(first),secondnum=NumberFromList(second);
      int total=firstnum+secondnum;
      return ListFromNumber(total);
  
    }
    
  /*
  This funtion is used to return an integer value from the lsit that can be used to calculte the Sum
  it goes thorugh the list adding in exponents of ten
  */
    private static int  NumberFromList(LinkedList<Integer> list ){
  int num=0;
  int exponent=list.size()-1;
  for(Integer i: list){
  num+=i.intValue()*((int)Math.pow(10, exponent));
  exponent--;
  }
  return num;
    }
  
  
    
    //Used to put numbers back into list format
    // extracts number in ones place and puts it in front of list
    //then add
    private static LinkedList<Integer> ListFromNumber(int a){
  int num=a;
  LinkedList<Integer> result= new LinkedList<>();
  while (num!=0){
    result.addFirst(Integer.valueOf(num%10));
    num=num/10;
  }
  
  return result;
    }
  
    public static LinkedList<Character> ReversedGramaticly(LinkedList<Character> list){
  
      LinkedList<Character> buffer= new LinkedList<>(),result =new LinkedList<>();
      for (int i=list.size()-1;i>-1;i--){
      Character c=list.get(i);
      System.out.println(c);
      if((c.charValue()==' ') || (i==0) ) {
      
      if((buffer.size()>0)){
        for (int j =buffer.size()-1;j>-1;j--){   
        result.addLast(buffer.get(j));
        }
        buffer.clear();
          }
      
        result.addLast(Character.valueOf(c));
      }else{    buffer.addLast(c);  }
      
      }
      return result;
      
      
      
        }


        public static void main(String[] args) {
            LinkedList<Character> list= new LinkedList();
            list.add(Character.valueOf('H'));
            list.add(Character.valueOf('A'));
            list.add(Character.valueOf('T'));
            list.add(Character.valueOf(' '));
            list.add(Character.valueOf('S'));
            list.add(Character.valueOf('H'));
            System.out.println(ReversedGramaticly(list));

        }
      
  }