
public class Reverse { 
    public Reverse(char Take_in, Reverse After_in) 
    { 
        Take = Take_in; 
        After = After_in; 
    } 
    public char Take; 
    public Reverse After; 
} 
class Function_check { 
  

    private static Reverse Switch_string(String hold_string) 
    { 
        Reverse top_on = null; 
        Reverse tester = null; 

        for (int i = 0; i < hold_string.length(); i++) { 
            char charact = hold_string.charAt(i); 
            Reverse node = new Reverse(charact, null); 
  
            if (top_on == null) { 
                top_on = node; 
                tester = top_on; 
            } 
            else { 
                tester.After = node; 
                tester = tester.After; 
            } 
        } 
        return top_on; 
    } 
  

    private static Reverse Reverse(Reverse top_on) 
    { 
        if (top_on == null) 
            return top_on; 
  
        Reverse Start_on = null; 
        Reverse last = null; 
        Reverse start_p = null; 
  

        Start_on = top_on; 

        while (top_on != null && top_on.Take != ' ') { 

            last = top_on; 
  
            top_on = top_on.After; 
        } 

        if (top_on == null) { 
            top_on = Start_on; 
            return top_on; 
        } 
  
        do { 
  
           
            Reverse tester = top_on.After; 
            top_on.After = Start_on; 
            Start_on = top_on; 
            top_on = tester; 
  
            Reverse prev = null; 
        
            start_p = top_on; 
  

            while (top_on != null && top_on.Take != ' ') { 
                prev = top_on; 
                top_on = top_on.After; 
            } 
  
 
            prev.After = Start_on; 
  
 
            Start_on = start_p; 
            if (top_on == null) 
                break; 
  

        } while (top_on != null); 
  
        top_on = start_p; 
  
    
        last.After = null; 
        return top_on; 
    } 
  

    private static void show_off(Reverse Header) 
    { 
        Reverse tester = Header; 

        while (tester != null) { 
            System.out.print(tester.Take); 
            tester = tester.After; 
        } 
    } 
  
 
    public static void main(String[] args) 
    { 
        String hold_string = "I love Geeks for Geeks"; 
  
        Reverse top_on = Switch_string(hold_string); 
  
        top_on = Reverse(top_on); 
  
        System.out.println("\nAfter:"); 
        show_off(top_on); 
    } 
} 