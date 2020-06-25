import java.util.LinkedList;
import java.util.ListIterator;
import java.util.NoSuchElementException;

public class Firaol_Woldemariam_Week4_part_2 {
    public static void main(String args[])
    {
        LinkedList<String> test = new LinkedList<String>();
        test.add("I");
        test.add("t");
        test.add(" ");
        test.add("i");
        test.add("s");
        
        System.out.println("Reversed: " + LLreverseWord(test));
    }
    
    public static LinkedList<String> LLreverseWord(LinkedList<String> sentence)
    {
        LinkedList<String> words = new LinkedList<String>();
        LinkedList<String> reversed = new LinkedList<String>();
        
        ListIterator<String> iter = sentence.listIterator();
        
        String word = "";
        
        if(!iter.hasNext())
        {
            throw new NoSuchElementException();
        }
        while(iter.hasNext())
        {
            if(iter.next().equals(" "))
            {
                words.add(word);
                words.add(" ");
                word = "";
            }
            else {
               word = word.concat(iter.next());
            }
        }
        System.out.println(words);
        ListIterator<String> iter2 = words.listIterator();
        while(iter2.hasPrevious())
        {
            reversed.add(iter2.previous());
        }
        return reversed;
    }
    
}
