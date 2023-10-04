#include <bits/stdc++.h>
using namespace std;

int signum(int a, int b){
    if(a==b) return 0;
    return a<b ? -1 : 1;
}

void callMedian(int element, priority_queue<int> &maxi, priority_queue<int, vector<int>, greater<int> > &mini, int median){
    switch(signum(maxi.size(), mini.size())){
        case 0: //both are of same size
            if(element < median){
                maxi.push(element);
                median = maxi.top();
            }
            else{
                mini.push(element);
                median = mini.top();
            }
            break;
        case 1: //maxHeap has more elements
            if(element < median){
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(element);
            }
            else{
                mini.push(element);
            }
            median = (maxi.top() + mini.top())/2;
            break;
        case -1: //minHeap has more elements
            if(element < median){
                maxi.push(element);
            }
            else{
                maxi.push(mini.top());
                mini.pop();
                mini.push(element);
            }
            median = (maxi.top() + mini.top())/2;
            break;
    }
    
}

vector<int> findMedian(vector<int> &arr, int n){
    vector<int> ans;
    priority_queue<int> maxHeap; //maxHeap
    priority_queue<int, vector<int>, greater<int>> minHeap; //minHeap
    int median = 0;
    for(int i=0; i<n; i++){
        callMedian(arr[i], maxHeap, minHeap, median);
        ans.push_back(median);
    }
    return ans;
}

int main(){

    vector<int> arr = {5, 15, 10, 20, 3};
    int n = arr.size();
    vector<int> ans = findMedian(arr, n);
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}
