#include <bits/stdc++.h>
using namespace std;

// int solve(vector<int> &coins, int k){
//     //base case
//     if(k==0) return 0;
//     if(k<0) return INT_MAX;

//     int mini = INT_MAX;
//     for(int i=0; i<coins.size(); i++){
//         int res = solve(coins, k-coins[i]);
//         if(res!=INT_MAX){
//             mini = min(mini, res+1);
//         }
//     }
//     return mini;
// }

/*MEMOISATION*/
// int solve2(vector<int> &coins, int k, vector<int> &dp){
//     //base case
//     if(k==0) return 0;
//     if(k<0) return INT_MAX;

//     if(dp[k]!=-1) return dp[k];

//     int mini = INT_MAX;

//     for(int i=0; i<coins.size(); i++){
//         int res = solve2(coins, k-coins[i], dp);
//         if(res!=INT_MAX){
//             mini = min(mini, res+1);
//         }
//     }
//     return dp[k] = mini;
// }

/*TABULATION*/
int solve3(vector<int> &coins, int k){
    vector<int> dp(k+1, INT_MAX);
    dp[0] = 0;

    for(int i=1; i<=k; i++){
        for(int j=0; j<coins.size(); j++){
            if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX)
            dp[i] = min(dp[i], dp[i-coins[j]]+1);
        }
    }
    if(dp[k]==INT_MAX) return -1;

    return dp[k];
}


int minCoins(vector<int> &coins, int k){
    /*solve*/
    // int res = solve(coins, k);
    // if(res==INT_MAX) return -1;
    // return res;

    /*memoisation*/
    // vector<int> dp(k+1, -1);
    // int ans = solve2(coins, k, dp);
    // if(ans==INT_MAX) return -1;
    // return ans;

    /*tabulation*/
    return solve3(coins, k);

}

int main(){
    
    vector<int> coins = {9, 6, 5, 1};
    int k = 10;
    cout<<minCoins(coins, k)<<endl;
    
    return 0;
}