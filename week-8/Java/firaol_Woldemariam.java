public class firaol_Woldemariam{
    
    public static void main(String args[])
    {
        
    }
    
    private static int search(int[] array, int key)
    {
        int high = array.length - 1;
        int low = 0;
        
        while(low <= high)
        {
            int mid = (low + high);
            if(array[mid] < key)
            {
                low = mid + 1;
            }
            else if(array[mid] > key && array[mid - 1] >= key)
            {
                high = mid - 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
    
    public static int daysToCollect(int[] days, int stones)
    {
        int[] total = new int[days.length];
        total[0] = days[0];
        for(int i = 1; i < days.length; i++)
        {
            total[i] = total[i - 1] + days[i];
        }
        
        return search(total, stones) + 1;
    }
    
    public static int smallestNumber(int[] array, int key)
    {
        Arrays.sort(array);
        int amount = 0;
        int currentAmount = 0;
        for(int i = 0; i < array.length; i++)
        {
            int current = array[i];
            if(currentAmount != current && amount == key)
            {
                break;
            }
            else if(amount != key && currentAmount != current)
            {
                amount = 1;
                currentAmount = current;
            }
            else {
                amount++;
            }
        }
        return currentAmount;
    }
}