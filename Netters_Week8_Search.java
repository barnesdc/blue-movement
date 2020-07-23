import java.util.*;

class Netters_Week8_Search {
  public static void main(String[] args) {
  int[] arr = {2,2,1,3,1};
  int K = 2;
	System.out.println("The lowest integer repeated K times is: "+RepeatedK(K, arr));

  int[] days = {1,2,3,4,5};
  int stones = 4;
  
  System.out.println("Amount of days it took to get M stones "+StoneLove(days, stones));
  }


  public static int StoneLove(int[] Ndays, int Mstones){
    int[] Max = new int[Mstones];
    int[] totals = {3,8,10,14};
    Max[0] = Ndays[0];

    for(int i =0; i < Ndays.length-1; i++){
      Max[i] = (Ndays[i] -1)+ Ndays[i];
    }

    for(int j = 0; j < Max.length - 1; j++){
      if(totals[j] <= Max[j]){
      return Arrays.binarySearch(Max, Mstones);
      }
    }

    return Arrays.binarySearch(Max, Mstones) + 1;
  }
  
  public static int RepeatedK (int K, int[] arr){
    Arrays.sort(arr);
    int count = 0;
    int N = 0;

    for(int i = 0; i < arr.length; i++){
      if(count != K && arr[i] != N){
        count = 1;
        N = arr[i];
      }
      else if(arr[i]!= N && count == K){
        break;
      }
      else{
        count++;
      }

    }

   return N;
  
  }

}