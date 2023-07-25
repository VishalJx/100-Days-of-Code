#include <bits/stdc++.h>
using namespace std;

/*--> Binary search is only applicable for monotonous functions
(either increasing or decreasing) or on SORTED ARRAYS*/

/*-->Three parameters are required.
1. Sorted Array.
2. Size of array.
3. "key" to be searched inside the sorted array.
*/
int binarySearch( int arr[], int size, int key){

    //starting index
    int start = 0;
    //end index 
    int end = size-1;;

    //middle index 
    //--> Not a proper way to calculate mid 'cause :- SEE BELOW THE CODE
        int mid = (start + end)/2;

    /*-->for increasing sorted array the condition will be "start<=end" 
        Here "end" must be ahead from the "start";
    */
    while(start <= end){
        //to search at mid index
        if(arr[mid] == key){
            return mid;
        }
        //to go towards right indices
        if(arr[mid] < key){
            start = mid + 1; //new start point(just one index greater than mid index)
            // And by default "end" is still the same i.e. "end = 0"
        }
        //to go towards left indices
        if(arr[mid] > key){
            end = mid - 1; //new end point(just one index lesser than mid index)
            // And by default "start" is still the same i.e. "start = 0"
        }
        /*--> If original mid is not the key then;
        1. "start" is updated
        2. "end" is updated
        3. new mid is created from update 'start' and 'end'
        */
        mid = (start + end)/2; //SEE BELOW THE CODE
    }
    //if key is not present in the given sorted array then;
    return -1;


}

int main()
{
    int even[6] = {2,4,6,8,10,12};
    int key = 12;
    int index = binarySearch(even, 6, 12); //storing the returned value in a variable
    cout<<"Index of " << key<< " is: "<<index<<endl;

    return 0;
}

/*
1. Max value of int is (2^31) - 1
2. Hence if let's assume a case where start = end = (2^31) - 1;
    then on their addition; the value of 'int' overflows.
3. CORRECT WAY : start + ((end - start)/2)  --> ofcourse for increasing sorted array.
    Maths : (s/2)+(e/2)
          = (s-s/2) + (e/2)
          = (s) + ((e/2)/(s/2))
          = (s) + ((e-s)/2) 
*/
 /*
    TIME COMPLEXITY: O(log n)
    1. On each iteration, the size of array reduces to half.(N; N/2; N/4....1)
    2. Hence on n-th iteration the size of array reduces by N/2^k.
    3. Goes till the size of array becomes  1 therefore ;-
        N/2^k = 1;
        k = log(N)
 */