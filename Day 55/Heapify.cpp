#include <bits/stdc++.h>
using namespace std;

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

int main(){
    int arr[] = { -1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };

    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = 0; i < n-1; i++)  //n-1 just to skip the -1 element
        cout << arr[i] << " ";  
    
    return 0;
}