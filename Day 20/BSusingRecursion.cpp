#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int arr[], int size, int key, int start, int end){
    
    if(size==0)
        return false;
    if(size==1)
        return arr[0]==key;

    int mid=(start+end)/2; //Simply calculating mid

    if(arr[mid]==key)
        return true;
    else if(arr[mid]>key)
        return binarySearch(arr,size/2,key,start,mid-1); //Similiar to while loop, we are reducing the size of the array by half each time.
        //Above, new end will be mid-1, i.e. we are seraching in left half of the array.
    else
        return binarySearch(arr,size/2,key,mid+1,end);
        //Above, new start will be mid+1, i.e. we are seraching in right half of the array.
}
 
int main() {

    int arr[]={1,2,3,4,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    int key=5;
    cout<<binarySearch(arr,size,key,0,size-1);

    return 0;
}