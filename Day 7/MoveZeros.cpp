#include <bits/stdc++.h>
using namespace std;

void moveZero(vector<int>arr){
    int size = arr.size();
    int i = 0;
    for(int j =0; j<size; j++){
        if(arr[j] != 0){
            swap(arr[i],arr[j]);
            i++;
        }
    }

    for(int p=0; p<size; p++){
        cout<<arr[p];
    }
}
 
int main() {
    vector<int>arr={0,5,0,3,0,8};
    moveZero(arr);

    return 0;
}