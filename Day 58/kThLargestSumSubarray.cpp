#include <bits/stdc++.h>
using namespace std;

//Brute Force: O(n^2)
// int kthLargestSum(vector<int> &arr, int n, int k){
//     //storing sums of all subarrays
//     vector<int> sumStore;
//     //sum of subarray
//     for(int i=0; i<n; i++){
//         int sum = 0;
//         cout<<i+1<<"th subarray: ";
//         for(int j=i; j<n; j++){
//             cout<<arr[j]<<" "<<endl;
//             sum += arr[j];
//             sumStore.push_back(sum); //storing sum of subarray
//         }
//     }
//     //sorting the sumStore
//     sort(sumStore.begin(), sumStore.end());
//     //returning kth largest sum
//     return sumStore[sumStore.size()-k];
// }

//Optimised:O(n)
int kthLargestSum(vector<int> &arr, int n, int k){
    //creating min heap
    priority_queue<int, vector<int>, greater<int>> mini;

    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            if(mini.size() < k){
                mini.push(sum);
            }
            else{
                if(mini.top() < sum){
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }   
    return mini.top();
}

int main(){

    vector<int> arr = {1,2,3};
    int n = arr.size();
    int k = 7;

    cout<<kthLargestSum(arr, n, k);
    
    return 0;
}