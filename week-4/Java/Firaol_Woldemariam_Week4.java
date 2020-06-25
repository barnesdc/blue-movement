import java.util.LinkedList;
import java.util.ListIterator;

public class Firaol_Woldemariam_Week4{
    
    public static void main(String args[])
    {
        LinkedList<Integer> firstNum = new LinkedList<Integer>();
        LinkedList<Integer> secondNum = new LinkedList<Integer>();
        firstNum.add(5);
        firstNum.add(3);
        firstNum.add(2);
        secondNum.add(6);
        secondNum.add(8);
        System.out.println(LLsums(firstNum, secondNum));
    }
    
    public static int LLsums(LinkedList<Integer> first, LinkedList<Integer> second)
    {
        int firstAmount = 0;
        int secondAmount = 0;
        int total = 0;
        int firstSize = first.size() - 1;
        int secondSize = second.size() - 1;
        for(int i = 0; i < first.size(); i++)
        {
            int digit1 = (int)(first.get(i) * Math.pow(10, firstSize));
            firstAmount = firstAmount + digit1;
            firstSize--;
            for(int j = 0; j < second.size(); j++)
            {
                int digit2 = (int)(second.get(j) * Math.pow(10, secondSize));
                secondAmount = secondAmount + digit2;
                secondSize--;
            }
        }
        total = firstAmount + secondAmount;
        return total;
    }
    
}