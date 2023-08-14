#include <bits/stdc++.h>
using namespace std;

bool linearSearch(int arr[], int size, int key){
    if(size==0) //Base Case: At the end of the recursion, if the size of the array is 0, then the element is not present in the array.
        return false;
    if(arr[0]==key) //Base Case: Each time we compare only the first element of the array with the key.
        return true;

    return linearSearch(arr+1,size-1,key); //Each time array size is decreased by 1 and the array is shifted by 1.
    //Each time when array is shifted by 1, the first element of the array is compared with the key.
}
 
int main() {

    int arr[]={1,2,3,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    int key=3;
    cout<<linearSearch(arr,size,key);
 
    return 0;
}