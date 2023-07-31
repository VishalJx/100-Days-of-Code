#include <bits/stdc++.h>
using namespace std;

//This is how swap function works internally

// int swap(int *i , int *j){
//     int temp = *i;
//     *i = *j;
//     *j = temp;
// }

int selectionSort(int arr[], int size){
    for(int i = 0; i<size; i++){
        for(int j = i+1;j<size; j++){
            //condition to check smaller element as compared to i-th index element.
            if(arr[j]<arr[i])
                swap(arr[i],arr[j]); //inbuilt swap function
        }
    }
    //printing the sorted array.
    for(int p=0; p<size;p++){
        cout<<arr[p];
    }
    return 0;
}
 
int main() {

    int arr[5]={5,6,4,2,3};
    
    selectionSort(arr,5);

    return 0;
} 

/* -------------WORKING------------------
    1. We consider 2 pointers i and j.
    2. i points at first element and j point at i+1(one element ahead of i-index).
    3. j pointer interates over the array after i-index and search
        for element smaller than i-index.(arr[i]>arr[j]).
    4. As soon as such element is found, we swap i-th index element with j-th index element.
    5. Basically at first we consider i-th element to be smallest and then search for
        other element smaller than i-th index element and swap it with it.
*/

/*-----------Space Complexity-------------
    As we have only defined the variables but have not taken any extra space.
    Hence space complexity will be O(1)
*/

/*-----------Time Complexity---------------
    Worst Case- Iterating over each element and each has to be swapped----> O(n^2)
    Best Case- Already sorted array(Still we are making comparisons)---> O(n^2)
*/

// UNSTABLE SORTING ALGORITHM