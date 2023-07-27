#include <bits/stdc++.h>
using namespace std;

//As we learnt from the last question that how to find a pivot element.
//We'll be using that concept to find the target element
/*KEY POINTS TO REMEMBER
    [1]. A pivot element divides the rotated array into two part.
    [2]. Part 1 sorted and also Part 2 is sorted.
    [3]. We'll apply binary search on both parts on by one.
    [4]. The part having our target element will return the target.

*/
int findPivot(int arr[], int size){  //Finding Pivot
    int start, end, mid;
    start = 0;
    end = size - 1;
    mid = start + (end - start)/2;

    while(start < end){
        if(arr[mid] >= arr[0])
            start = mid + 1;

        else // arr[mid] < arr[0]
            end = mid;
        
        mid = start + (end - start)/2;
    }

    return start;
}

//Main code to find target using pivot
int targetValueIndex(int arr[],int target, int size){

    int pivot = findPivot(arr,size); //calling pivot index

    //Defined below to part the arrays taking pivot as reference
    int start, mid;
    start = 0;
    int end = size - 1;


    //Applying binary search on 2nd part. i.e. between pivot and end element(both inclusive)
    if((arr[pivot] <= target) && (target <= arr[end])){

        start = pivot;
        end = size - 1;
        mid = start + (end - start)/2;

        while(start < end){
            if(arr[pivot+mid] == target)
                return target;
            if(arr[pivot+mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
            
        mid = start + (end - start)/2;
        }
        return mid;
    }

    //Applying binary search on 1st part where start is at 0th index and end will be the element just before the pivot: (pivot - 1).
    else{
        end = pivot - 1;
        mid = start + (end - start)/2;

        while(start < end){
            if(arr[mid] == target)
                return target;
            if(arr[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
            
        mid = start + (end - start)/2;
        }
        return mid;
    }

}

 
int main() {
    int arr[5] = {4,6,10,1,2};
    int target = 6;

    int size = sizeof(arr)/sizeof(arr[0]);

    cout << targetValueIndex(arr, target, size);
    return 0;
}

/* --------------------------------------------------------------------------------------------------------------
            FAILED APPROACHS
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~1~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// int findTargetOnUpperPart(){
//     int arr[5] = {4,6,10,1,2};
//     int target;
//     target = 2;

//     int pivot;
//     pivot = findPivot(arr,5);

//     int start, end, mid;
//     start = 0;
//     end = pivot - 1;
//     mid = start + (end-start)/2;

//     while(start < end){
//         if(arr[mid] == target)
//             return mid;

//         if(arr[mid] > target)
//             end = mid - 1;

//         if(arr[mid] < target)
//             start = mid + 1;

//         mid = start + (end-start)/2;

//     }
//     return mid;
    
// }


// int findTargetOnLowerPart(){
//     int arr[5] = {4,6,10,1,2};
//     int target;
//     target = 2;

//     int pivot;
//     pivot = findPivot(arr,5);

//     int start, end, mid;
//     start = pivot;
//     end = 5;
//     mid = start + (end-start)/2;

//     while(start < end){
//         if(arr[pivot + mid] == target)
//             return mid;

//         if(arr[pivot + mid] > target)
//             end = mid - 1;

//         if(arr[pivot + mid] < target)
//             start = mid + 1;

//         mid = start + (end-start)/2;

//     }
//     return mid;
    
// }

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~2~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// int targetValueIndex(){
//     int arr[5] = {4,6,10,1,2};
//     int size = 5;
//     int pivot = findPivot(arr,size);
//     int target = 2;

//     int start = 0, end = size - 1, mid;
//     mid = start + (end - start)/2;

//     while(start < end){
//         if(arr[mid] == target)
//             return mid;
//         if(arr[mid] >= target){
//             if(arr[mid] > arr[0]){
//                 start = mid + 1;
//             else

//             }
//         }
//     }

// }


*/