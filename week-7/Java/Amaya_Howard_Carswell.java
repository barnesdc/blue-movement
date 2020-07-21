import java.util.*;


class Amaya_Howard_Carswell {
    public static void KCount(int[] nums, int k) {

        /*Version that implements Scanner to take user input from terminal*/

        // Scanner s = new Scanner(System.in);
        // System.out.println("Enter some numbers. ");
        // String input = s.nextLine();
        // List<Integer> nums = new LinkedList<Integer>();
        //
        // for (String str : input.split(" "))
        //     nums.add(Integer.parseInt(str));
        //
        // System.out.println("Enter a number for k. ");
        // int k = s.nextInt();
        //
        // Collections.sort(nums);

        Arrays.sort(nums);

        int cnt = 0;
        int last = nums[0]; //nums.get(0);
        for (int i : nums){
            if (i == last) cnt++;
            else{ //
                if (cnt == k){
                    System.out.println(last);
                    break;
                }
                cnt = 1;
            }
            last = i;
        }


    }




    public static void Stones(int[] stones, int[] queries) {

        /*Version that implements Scanner to take user input from terminal*/

        // System.out.println("Enter numbers for the amount of daily stones. ");
        // Scanner s = new Scanner(System.in);
        // String input = s.nextLine();
        //
        // int sum = 0;
        // for (String str : input.split(" ")){
        //     sum += Integer.parseInt(str);
        //     stone_sums.add(sum);
        // }
        //
        // System.out.println("Enter numbers for the queries. ");
        // input = s.nextLine();
        // List<Integer> queries = new LinkedList<Integer>();
        //
        // for (String str : input.split(" "))
        //     queries.add(Integer.parseInt(str));
        //
        // Collections.sort(queries);
        Arrays.sort(queries);
        List<Integer> stone_sums = new LinkedList<Integer>();
        // Calculates the total amount of sums for each day
        int sum = 0;
        for (int i : stones){
            sum += i;
            stone_sums.add(sum);
        }

        int start = 0;
        for (int i = 0; i < queries.length; i++){
            for (int j = start; j < stone_sums.size(); j++){
                if (queries[i] <= stone_sums.get(j)){
                    System.out.println("It takes " + (j+1) + " days to get " + queries[i] + " stones.");
                    start = j;
                    break;
                }
            }
        }




    }

    public static void main(String[] args) {


        int[] nums = {1, 2, 2, 2, 3, 4, 4, 4, 5, 6, 7, 7, 8, 8};
        // Answer -> 7
        KCount(nums, 2);

        int[] stones = {2, 4, 1, 4, 5, 6};
        int[] queries = {3, 5, 8, 11, 17};
        // Answers -> 2, 2, 4, 4, 6
        Stones(stones, queries);
    }

}
