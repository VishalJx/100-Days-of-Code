#include <bits/stdc++.h>
using namespace std;

//What is a Derangement?
//In combinatorial mathematics, a derangement is a permutation of the elements of a set, 
//such that no element appears in its original position.


/*MEMOISATION*/
int solve(int n, vector<long long int> &dp){
    if(n == 1) return 0;
    if(n == 2) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = (n-1)*(solve(n-1, dp) + solve(n-2, dp));
}

/*Tabulation*/
int solve2(int n, vector<long long int> &dp){
    dp[1] = 0;
    dp[2] = 1;
    for(int i = 3; i <= n; i++){
        dp[i] = (i-1)*(dp[i-1] + dp[i-2]);
    }
    return dp[n];
}


long long int countDerangements(int n){
    /*Recursive Solution*/
    // if(n == 1) return 0;
    // if(n == 2) return 1;
    // return (n-1)*(countDerangements(n-1) + countDerangements(n-2));
    
    /*Memoisation*/
    // vector<long long int> dp(n+1, -1);
    // return solve(n, dp);

    /*Tabulation*/
    vector<long long int> dp(n+1, 0);
    return solve2(n, dp);
}

int main(){

    cout << countDerangements(4) << endl;
    
    return 0;
}