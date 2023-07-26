//Question:- Find pivot in a sorted and rotated array.
/*
What is pivot element in an array ?
    Pivot element is the only element in
    array which is smaller than
    it's previous element. A pivot element divided
    a sorted rotated array into two monotonically increasing array.
*/

#include <bits/stdc++.h>
using namespace std;

int pivotElement(int arr[], int size){
    int s = 0, e = size;
    int mid = s + (e-s)/2;

    while(s < e){
        if(arr[mid] >= arr[0]){ //This means mid lies on upper line(see diagram). Note that elements of below line are smaller than element arr[0];
            s = mid + 1; // To bring the mid closer to pivot element
        }
        else{
            e = mid; /* So that the if mid lies on pivot element or any where on bottom line
                        then on doing "e = mid - 1", it will take it back to upper line.*/
        }
        mid = s + (e-s)/2;
    }
    return s; //either "s" or "e" can be written cause at the end the pivot element will point as both "start" and "end"
}

int main()
{
    //sorted and rotated array;
    int arr[5] = {8,9,10,1,3}; 
    cout <<"Pivot element is: "<< arr[pivotElement(arr, 4)]<<endl;
    return 0;
}
