#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>arr){
    int count = 0;
    int size = arr.size();

    for(int i=1;i<size;i++){
        if(arr[i-1] > arr[i])
        count++;
    }
    if(arr[size-1] > arr[0])
        count++;
    
    return count<=1;
}
 
int main() {
    vector<int>arr={4,5,6,1,8};

    cout<<check(arr);

    return 0;
}