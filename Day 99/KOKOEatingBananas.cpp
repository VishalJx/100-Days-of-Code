#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(Nlog(max(piles[i])))
//Using Binary Search
int minEatingSpeed(vector<int>& piles, int h) {
    int s=1;
    //Just a STL to find maximum element but add complexity O(N)
    int e=*max_element(piles.begin(),piles.end());
    while(s<=e){
        int mid = s + (e-s)/2;
        //size_t to avoid integer overflow
        size_t hours=0;
        //checking for our each value in piles vector
        for(auto p: piles){
            hours += (p + mid - 1) / mid;
        }
        //The time we chose was not sufficient so look for values greater than mid
        if(hours>h){
            s=mid+1;
        }
        //there could be some smaller values than mid
        else{
            e=mid-1;
        }
    }
    return e+1;  //or simply just return s
}

int main(){

    vector<int> piles = {3,6,7,11};
    int h = 8;

    cout<<minEatingSpeed(piles,h);
    
    return 0;
}