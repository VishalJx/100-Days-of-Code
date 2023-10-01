#include <bits/stdc++.h>
using namespace std;

//MAXHEAP -> kth smallest element
//MINHEAP -> kth largest element

/*ALgorithm(without sorting)
    1. Convert first k-elements(from 0 to k-1) elements into heap.
    2. Compare if (root > kth element), 
               if yes, then delete root && insert kth element.
    3. 2nd step gives us k smallest elements of array.
*/


int kthSmallest(int arr[], int k, int n){

    priority_queue<int> maxHeap;
    //STEP 1
    for(int i=0; i<k; i++){ //only 0 to k-1 elements
        maxHeap.push(arr[i]);
    }
    //STEP 2
    for(int i=k; i<=n; i++){ //from k to n-1 elements
        if(maxHeap.top() > arr[i]){
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }
    //STEP 3
    return maxHeap.top();
}

int main(){
    int arr[] = {7, 10, 4, 3, 20, 15};
    //sorted form : 3, 4, 7, 10, 15, 20
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 7;
    cout<<kthSmallest(arr, k, n-1);
    
    return 0;
}