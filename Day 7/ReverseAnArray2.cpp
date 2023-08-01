//Reverse an array after the Mth index.

#include <bits/stdc++.h>
using namespace std;

int reversedArray(vector<int>arr, int point){
    int size = arr.size();
    int start = point + 1; //we need to start from here
    int end = size-1; //till the end

    for(int i=start;i<end;i++){
        swap(arr[i], arr[end--]); //end-- as we need to iterate backward
        //i++; already written in for loop
    }

    //printing array
    for(int p=0;p<size;p++){
        cout<<arr[p];
    }
    return 0;
}
 
int main() {
    vector <int> arr={5,1,4,3,6,9,7};
    int M = 2;

    reversedArray(arr,M);

    return 0;
}