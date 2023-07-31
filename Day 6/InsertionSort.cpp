#include <bits/stdc++.h>
using namespace std;

int insertionSort(int arr[], int size){
    int value;  //First element of the unsorted array
    int hole;   //First element's index of the unsorted array 

    /*As we are considering very first element of the array to be sorted
    and rest of the array to be unsorted, We initialise i=1 cause i=0 is sorted element.*/
    for(int i=1; i<=size; i++){
        value = arr[i]; //value of the very first element of the unsorted array.
        hole = i; //index of the very first element of the unsorted array.
        /*
            ->Checking hole>0, because at hole=0 all elements will be sorted.
            ->Note, hole is travelling in negative direction.
            ->arr[hole-1]>value means value(first element's of unsorted array) is smaller than the element in sorted array.
              then we need to switch both with each other.
        */
        while(hole > 0 && arr[hole-1]>value){
            arr[hole] = arr[hole-1];//replace element of unsorted array with element of sorted array,
                                    // cause element in sorted array is larger(we checked above in while() condition) hence it has to be replaced
            hole = hole-1; //updating the value of hole to move towards sorted array
        }
        arr[hole] = value; //new value of "value" will be new "hole's" value
    }
    return 0;
}
 
int main() {

    int arr[5]={5,6,4,2,3};
    insertionSort(arr,5);

    return 0;
}

/*-------------------WORKING------------------
    1. We divide array into two parts, considering first element to be sorted and rest elements to be 
        unsorted.
    2. We compare an element at "hole", with each elements in sorted part and if there's space for unsorted 
    element inside sorted array, then we put it there(check while condition)

*/

/*-----------------Time Complexity-------------
    Worst Case: O(n^2)
    Best Case:O(n)
*/

// STABLE SORTING ALGORITHM