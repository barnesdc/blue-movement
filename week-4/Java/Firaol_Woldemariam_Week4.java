import java.util.LinkedList;

public class Firaol_Woldemariam_Week4{
    
    public static void main(LinkedList args[])
    {
        LLSums(args[1], args[2]);
    }
    
    public static double LLSums(LinkedList<Integer> first, LinkedList<Integer> second)
    {
        double firstAmount = 0;
        double secondAmount = 0;
        double total = 0;
        int firstSize = first.size() - 1;
        int secondSize = second.size() - 1;
        for(int i = 0; i < first.size() - 1; i++)
        {
            double digit1 = first.get(i) * Math.pow(10, firstSize);
            firstAmount = firstAmount + digit1;
            firstSize--;
            for(int j = 0; j < second.size() - 1; j++)
            {
                double digit2 = second.get(j) * Math.pow(10, secondSize);
                secondAmount = secondAmount + digit2;
                secondSize--;
            }
        }
        total = firstAmount + secondAmount;
        return total;
    }
    
    public static LinkedList<String> LLreverseWord(LinkedList<String> word)
    {
        return word;
    }
}