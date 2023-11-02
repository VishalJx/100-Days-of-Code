#include <bits/stdc++.h>
using namespace std;

/*RECURSION*/
int solve(int n){
    //Base Case
    if(n == 0){
        return 0;
    }
    int ans = n;
    for(int i = 1; i * i <= n; i++){
        ans = min(ans, 1 + solve(n - i * i));
    }
    return ans;
}

/*MEMOISATION*/
int solve2(int n, vector<int> &dp){
    //Base Case
    if(n == 0){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int ans = n;
    for(int i = 1; i * i <= n; i++){
        ans = min(ans, 1 + solve2(n - i * i, dp));
    }
    return dp[n] = ans;
}

/*TABULATION*/
int solve3(int n){
    vector<int> dp(n + 1, 0);
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        dp[i] = i;
        for(int j = 1; j * j <= i; j++){
            dp[i] = min(dp[i], 1 + dp[i - j * j]);
        }
    }
    return dp[n];
}

int MinSquare(int n){
    /*Recursive Sol*/
    // return solve(n);

    /*Memoisation*/
    // vector<int> dp(n + 1, -1);
    // return solve2(n, dp);

    /*Tabulation*/
    return solve3(n);
}

int main(){
    
    cout << MinSquare(6) << endl;
    return 0;
}