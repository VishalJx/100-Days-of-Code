// Question Link : https://leetcode.com/problems/peak-index-in-a-mountain-array/


#include <bits/stdc++.h>
using namespace std;

int peakIndex(int arr[], int size){
    int s = 0, e = size;
    int mid = s + (e-s)/2;
    while(s < e){ //since as soon as we reach at the only left element in array, that will be the final result and it must not iterate further.

        if(arr[mid] < arr[mid + 1]){ //for the left edge of the mountain.
            s = mid + 1;
        }
        else   // for the right edge and peak of the mountain
        { 
            e = mid; /* So that the if mid lies on peak index or any where on right side of mountain
                        then on doing "e = mid - 1", it will take it back to left side.*/
        }
        mid = s + (e-s)/2;
    }
    return s; //either "s" or "e" can be written cause at the end(last element left) the peak index will point as both "start" and "end";

}

int main()
{
    int mountainArr[5] = {0,2,1,0};
    cout <<"Peak element is at index: "<< peakIndex(mountainArr, 5);
    return 0;
} 