#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int add(int a, int b){
    return (a%MOD + b%MOD) %MOD;
}

int multiply(int a, int b){
    return ((a%MOD) * (b%MOD)) %MOD;
}

/*Recursive solution*/
// int solve(int n, int k){
//     // //base case
//     // if(n==1) return k;
//     // if(n==2) return add(k, multiply(k-1, k));

//     // int ans = add(multiply(k-1, solve(n-2, k)), multiply(k-1, solve(n-1, k)));

//     // return ans;
// }

/*MEMOISATION*/
int solve1(int n, int k, vector<int> &dp){
    //base case
    if(n==1) return k;
    if(n==2) return add(k, multiply(k-1, k));

    if(dp[n] != -1) return dp[n];

    int ans = add(multiply(k-1, solve1(n-2, k, dp)), multiply(k-1, solve1(n-1, k, dp)));

    return dp[n] = ans;
}

/*TABULATION*/
int solve3(int n, int k){
    vector<int> dp(n+1, 0);
    dp[1] = k;
    dp[2] = add(k, multiply(k-1, k));

    for(int i=3; i<=n; i++){
        dp[i] = add(multiply(k-1, dp[i-2]), multiply(k-1, dp[i-1]));
    }

    return dp[n];
}

int numberOfWays(int n, int k){
    /*Recursive solution*/
    // int ans = solve(n, k);
    // return ans;

    /*Memoisation*/
    // vector<int> dp(n+1, -1);
    // return solve1(n, k, dp);

    /*Tabulation*/
    return solve3(n, k);
}

int main(){

    cout<<numberOfWays(3, 2)<<endl;
    
    return 0;
}