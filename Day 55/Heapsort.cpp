#include <bits/stdc++.h>
using namespace std;

/*Algorithm
    1. swap the first and last element
    2. decrease the size of heap by 1(consider only remaining elements)
    3. take root to its correct position - heapify
    4. swap the first and last element(again)
    5. repeat
*/

void heapify(int arr[], int n, int i)  {
    int largest = i; // Initialize largest as root
    int left = 2*i; 
    int right = 2*i + 1;

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) 
        largest = left;
    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }

}

void heapSort(int arr[], int n){

    while(n>1){
        //Step 1
        swap(arr[0], arr[n-1]);
        //Step 2
        n--;
        //Step 3
        heapify(arr, n, 0);
    }
}

int main(){

    int arr[] = { -1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };

    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=n/2-1; i>=0; i--)
        heapify(arr, n, i);

    heapSort(arr, n);

    for(int i=0; i<n-1; i++)
        cout<<arr[i]<<" ";
    
    return 0;
}