#include <bits/stdc++.h>
using namespace std;

//=> 1. Top Down Approach:- Recursion + Memoization(storing the result of the function call)
//=> 2. Bottom Up Approach:-  Tabulation

//Top Down Approach
int fib(int n, vector<int> &dp){
    //base
    if(n == 0 || n == 1)
        return n;

    //Check if the state is already computed
    if(dp[n] != -1)
        return dp[n];
    
    dp[n] = fib(n-1, dp) + fib(n-2, dp);

    return dp[n];
}

//Bottom Up Approach
int fib(int n){
    vector<int> dp(n+1, 0);

    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
} 

int main(){

    int n;
    cin>>n;

    //to store the result of the function call
    //initially all the values are -1
    vector<int> dp(n+1, -1);

    cout<<fib(n, dp)<<endl;
    
    return 0;
}