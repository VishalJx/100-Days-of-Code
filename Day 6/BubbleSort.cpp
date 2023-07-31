#include <bits/stdc++.h>
using namespace std;

//Unoptimised
void bubbleSort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        //processing j till size-ith element as after each iteration the size of array keeps decreasing.
        for(int j=0; j<size-i; j++){  //we are writing size-1 so that if j is at 2nc last element then j+1 can be compared with it.
            if(arr[j] > arr[j+1]){
                //comparing two consecutive elements each time
                swap(arr[j], arr[j+1]);
            }
        }
    }

}
 
int main() {

    int arr[5]={5,6,4,2,3};
    
    bubbleSort(arr,5);

    return 0;
}

/*-----------------WORKING------------------
    1. We have two pointers i and j. "i" keeps track of each no. of iterations over array.
    2. j compares itself with j+1(on element ahead).
    3. If element at j is larger than element at j+1, then swap.
    4. Remember, we are pushing the heavier(larger elements) at the end of the array.
    5. We keep repeating step 2 and 3 until we get sorted array.
    6. On each iteration of i, a heavier element is pushed at the end of the array.
*/

/*----------------Time Complexity------------
   Worst Case: O(n^2) ---> Reverse Sorted
   Best Case: O(n^2)--->Unoptimised
   Best Case: O(n)--->Optimised(we can check wheather the swapping is done or not
                                if not, then we do not need to count that swap making it more optimised)
*/


//Optimised(we check whether swapping is done or not)

// void bubbleSort(int arr[], int size){
//     for(int i=0; i<size-1; i++){
//  -----------> bool isSwapped = false;
//         //processing j till size-ith element as after each iteration the size of array keeps decreasing.
//         for(int j=0; j<size-i; j++){  //we are writing size-1 so that if j is at 2nc last element then j+1 can be compared with it.
//             if(arr[j] > arr[j+1]){
//                 //comparing two consecutive elements each time
//                 swap(arr[j], arr[j+1]);
// ----------------> isSwapped = true
//             }
//         }
                    //Already Sorted
// ---------------->if(isSwapped == false){
//                         break;
//                 }
//     }

// }