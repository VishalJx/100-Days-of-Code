#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

// int solve(vector<int>& cost, int n){
//     //base case
//     if(n == 0 || n == 1){
//         return cost[n]; //cost[0] or cost[1]
//     }

//     int ans = cost[n] + min(solve(cost, n-1), solve(cost, n-2));
//     return ans;
// }

//MEMOISATION
int solve2(vector<int>& cost, int n, vector<int>& dp){
    //base case
    if(n == 0 || n == 1){
        return cost[n]; //cost[0] or cost[1]
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int ans = cost[n] + min(solve2(cost, n-1, dp), solve2(cost, n-2, dp));
    return dp[n] = ans;
}

//TABULATION
int solve3(vector<int>& cost, int n){
    vector<int> dp(n+1, -1);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i=2; i<=n; i++){
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }

    return min(dp[n-1], dp[n-2]);
}

//SPACE OPTIMISED
int solve4(vector<int>& cost, int n){
    int a = cost[0];
    int b = cost[1];
    int c;

    for(int i=2; i<=n; i++){
        c = cost[i] + min(a, b);
        a = b;
        b = c;
    }

    return min(a, b);
}


int minCostClimingStairs(vector<int>& cost) {
    // int n = cost.size();
    // int ans = min(solve(cost, n-1), solve(cost, n-2));
    // return ans;

    /*Memoisation*/
    int n = cost.size();
    vector<int> dp(n+1, -1);
    int ans = min(solve2(cost, n-1, dp), solve2(cost, n-2, dp));
    return ans;
}


int main(){
    vector<int> cost = {10, 15, 20};
    cout << minCostClimingStairs(cost) << endl;
    
    return 0;
}