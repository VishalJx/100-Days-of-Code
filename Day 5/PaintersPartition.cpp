//100% based on book allocation problem;


#include <bits/stdc++.h>
using namespace std;

bool isSolution(vector<int>boards , int mid, int painters){

    int painterCount = 1;
    int lengthCount = 0;
    int size = boards.size();

    for(int i=0; i < size; i++){
        if(lengthCount + boards[i] <= mid){
            lengthCount = lengthCount + boards[i];
        }
        else{
            painterCount++;
            if(painterCount > painters || boards[i] > mid){
                return false;
            }
            lengthCount = 0;
            lengthCount = boards[i];
        }
    }

}

int minTime(vector<int> boards, int painters){
    int size = boards.size();
    int start, end, mid;
    
    int sum = 0;
    for(int i=0; i<size; i++){
        sum += boards[i];
    }

    start = 0;
    end = sum;
    mid = start + (end-start)/2;

    int ans = -1;

    while(start <= end){
        if(isSolution(boards, mid, painters)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
        mid = start + (end-start)/2;
    }
    return ans;

}
 
int main() {

    vector<int> boards={10,20,30,40};
    int painters = 2;

    cout<<minTime(boards, painters);

    return 0;
}