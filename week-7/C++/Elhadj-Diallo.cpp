
#include <iostream>
using namespace std;
/*
 * Elhadj Diallo
 * IBM Bootcamp
 * Week-08
 * 2020-21-07*/


//-----------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Given a List of N number a1,a2,a3........an,
 * You have to find smallest number from the List that is repeated in the List exactly K number of times.
 * */
//find the smallest repeated number whithin an array
int findMinDuplNumber(int arr[], int n, int k)
{
    // Sort the array
    sort(arr, arr + n);

    // Find the first element with the exact k occurrences.
    int i = 0;
    for(i=0; i< n ; i++)    {
    int j, count = 1;
        for (j = i + 1; j < n && arr[j] == arr[i]; j++)
            count++;
        if (count == k)
            return arr[i];
    }

    return -1;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------



//-----------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Senorita likes stones very much. As she is f
 * ond of collecting beautiful stones, everyday she finds some of the s
 * tones beautiful and collects it in her bottle.*/
// returns index + 1  of value  or index of value right above
int Bs(int *arr, int sz, int key ){

    bool foundBool = false;
    int middle, smll = 0, large = sz - 1;

    while(smll <= large && foundBool == false){
        middle = (large + smll) / 2;

        if(arr[middle] > key)
            large = middle - 1;
        else if(arr[middle] < key)
            smll = middle + 1;
        else{
            foundBool = true;
            return middle + 1;
        }
    }
    if (!foundBool) return middle + 1;
    else return -1;
}

//binarySearch the sum array for each value in the query array(qarr)
void Qry(int arr[],int arr1len,int qarr[], int qarrlen){
    for(int i = 0; i< qarrlen; i++)
        cout << Bs(arr, arr1len, qarr[i]) << endl;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------
void Test_Case_findMinDuplNumber(){
    int arr[] = { 2, 20, 10, 3, 10,80,90 };
    int k = 2;
    int n = sizeof(arr) / (sizeof(arr[0]));
    cout << findMinDuplNumber(arr, n, k);
}

void Test_case_Stone_Love(){
    int ar1[] = {1, 2, 3, 4, 5},
            ar2[] = {3, 8, 10, 14};
    const int ar = sizeof(ar1) / sizeof(ar1[0]);
    int sumArr[ar], sum = 0;
    for(int i = 0; i < ar; i++) sum += ar1[i];
    sumArr[ar - 1] = sum;
    for(int i = ar - 2; i >= 0; --i)
        sumArr[i] = sum -=ar1[i + 1];
    Qry(sumArr, ar, ar2, sizeof(ar2) / sizeof(ar2[0]));

}
int main()
{
    Test_Case_findMinDuplNumber();
    cout<<endl;
    Test_case_Stone_Love();


    return 0;

}

//----------------------------------------------

#include <iostream>
using namespace std;


