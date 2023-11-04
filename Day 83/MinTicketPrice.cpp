#include <bits/stdc++.h>
using namespace std;


/*RECURSIVE SOLUTION*/
// int solve(int n, vector<int> days, vector<int> cost, int i){
//     //Base Case
//     if(i >= n){
//         return 0;
//     }

//     //for 1 day pass
//     int op1 = cost[0] + solve(n, days, cost, i+1);

//     //for 7 day pass
//     for(int j = i; j<n && days[j] < days[i] + 7; j++);
//     int op2 = cost[1] + solve(n, days, cost, i);

//     //for 30 day pass
//     for(int j = i; j<n && days[j] < days[i] + 30; j++);
//     int op3 = cost[2] + solve(n, days, cost, i);

//     return min(op1, min(op2, op3));

// }

/*MEMOISATION*/
// int solve2(int n, vector<int> days, vector<int> cost, int i, vector<int> &dp){
//     //Base Case
//     if(i >= n){
//         return 0;
//     }

//     if(dp[i] != -1){
//         return dp[i];
//     }

//     //for 1 day pass
//     int op1 = cost[0] + solve2(n, days, cost, i+1, dp);

//     //for 7 day pass
//     int j;
//     for(j = i; j<n && days[j] < days[i] + 7; j++);
//     int op2 = cost[1] + solve2(n, days, cost, j, dp);

//     //for 30 day pass
//     for(j = i; j<n && days[j] < days[i] + 30; j++);
//     int op3 = cost[2] + solve2(n, days, cost, j, dp);

//     return dp[i] = min(op1, min(op2, op3));

// }

/*TABULATION*/
int solve3(int n, vector<int> days, vector<int> cost){
    vector<int> dp(n+1, INT_MAX); //since we need to find min cost
    
    dp[n] = 0;

    //bottom up approach
    for(int i = n-1; i>=0; i--){
        //for 1 day pass
        int op1 = cost[0] + dp[i+1];

        //for 7 day pass
        int j;
        for(j = i; j<n && days[j] < days[i] + 7; j++);
        int op2 = cost[1] + dp[j];

        //for 30 day pass
        for(j = i; j<n && days[j] < days[i] + 30; j++);
        int op3 = cost[2] + dp[j];

        dp[i] = min(op1, min(op2, op3));
    }

    return dp[0];
}


int minCoins(int n, vector<int> days, vector<int> cost){
    /*Recursive Sol*/
    //  return solve(n, days, cost, 0);

    /*Memoisation*/
    // vector<int> dp(n+1, -1);
    // return solve2(n, days, cost, 0, dp);

    /*Tabulation*/
    return solve3(n, days, cost);
}

int main(){
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> cost = {2, 7, 15};

    cout<<minCoins(days.size(), days, cost)<<endl;
    return 0;
}