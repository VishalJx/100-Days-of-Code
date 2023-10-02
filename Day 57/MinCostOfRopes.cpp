#include <bits/stdc++.h>
using namespace std;

//We used min heap because it finds the minimum element 
//in O(1) time and we need to find the minimum element every time.
//similarly we can use max heap to find the maximum element 
//in O(1) time.

long long minCost(long long arr[], long long n) {
    //min heap
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(long long i=0; i<n; i++)
        pq.push(arr[i]);
    
    long long ans = 0; //cost at start
    while(pq.size()>1){
        long long a = pq.top(); //first min
        pq.pop();
        long long b = pq.top(); //second min
        pq.pop();
        ans += a+b;
        pq.push(a+b);
    }
    return ans;
}


int main(){
    long long arr[] = {4, 3, 2, 6};
    long long n = sizeof(arr)/sizeof(arr[0]);
    cout << "Total cost for connecting ropes is " << minCost(arr, n);
    
    return 0;
}