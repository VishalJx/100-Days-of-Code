#include <bits/stdc++.h>
using namespace std;

void mergeSortedArray(int nums1[],int m, int nums2[],int n,int nums3[]){
    int i=0, j=0, k=0;
    while( i < m &&  j < n){
        if(nums1[i]<nums2[j]){
            nums3[k] = nums1[i];
            k++;
            i++;
        }
        else{
            nums3[k] = nums2[j];
            k++;
            j++;
        }
    }
    while(i<n){
        nums3[k] = nums1[i];
        k++;
        i++;
    }
    while(j<m){
        nums3[k] = nums2[j];
        k++;
        j++;
    }
    for(int p=0;p<(m+n);p++){
        cout<<nums3[p];
    }

}
 
int main() {

    int arr1[4]={1,3,5,7};
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[3]={2,6,8};
    int n = sizeof(arr2)/sizeof(arr2[0]);
    int arr3[7]={0};

    mergeSortedArray(arr1,m, arr2,n ,arr3);

    return 0;
}