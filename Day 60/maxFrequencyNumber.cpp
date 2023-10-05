#include <bits/stdc++.h>
using namespace std;

int maxFrequency(vector<int> &arr, int n){
    unordered_map<int, int> count;

    int maxFreq = 0;
    int maxAns = 0;
    for(int i=0; i<n; i++){
        count[arr[i]]++; //counting the frequency of each element
        maxFreq = max(maxFreq, count[arr[i]]); //finding the maximum frequency
    }

    for(int i=0; i<n; i++){
        if(count[arr[i]] == maxFreq){
            maxAns = arr[i];
            break;
        }
    }

    return maxAns;
}

int main(){

    vector<int> arr = {1, 1, 2, 2, 2, 3};
    int n = arr.size();

    cout<<maxFrequency(arr, n)<<endl;
    
    return 0;
}