#include <bits/stdc++.h>
using namespace std;

int reverseArray(vector<int>arr, int size){

    int start = 0;
    int end = size;

    //calculated mid because we only need to iterate half of the array from each ends.
    int mid = start + (end - start)/2;

    for(int i=0;i<mid;i++){
        //swapping--> start elements with end elements
        swap(arr[i], arr[size-i-1]);
    }

    //printing array
    for(int p=0;p<size;p++){
        cout<<arr[p];
    }

    return 0;
}
 
int main() {
    vector <int> arr={5,1,4,3,6,7,2,5};
    int size = arr.size();

    reverseArray(arr,size);

    return 0;
}