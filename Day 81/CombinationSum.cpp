#include <bits/stdc++.h>
using namespace std;

/*RECURSIVE SOLUTION*/
// int solve(vector<int> &num, int tar, int n){
//     //Base Case
//     if(tar < 0){
//         return 0;
//     }
//     if(tar == 0){
//         return 1;
//     }

//     int ans = 0;
//     for(int i = 0; i < n; i++){
//         ans += solve(num, tar - num[i], n);
//     }
//     return ans;
// }

// /*MEMOISATION*/
// int solve2(vector<int> &num, int tar, int n, vector<int> &dp){
//     //Base Case
//     if(tar < 0){
//         return 0;
//     }
//     if(tar == 0){
//         return 1;
//     }

//     if(dp[tar] != -1){
//         return dp[tar];
//     }

//     int ans = 0;
//     for(int i = 0; i < n; i++){
//         ans += solve2(num, tar - num[i], n, dp);
//     }
//     return dp[tar] = ans;
// }

/*TABULATION*/
int solve3(vector<int> &num, int tar, int n){
    vector<int> dp(tar + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= tar; i++){
        for(int j = 0; j < n; j++){
            if(i - num[j] >= 0){
                dp[i] += dp[i - num[j]];
            }
        }
    }
    return dp[tar];
}

int findWays(vector<int> &num, int tar){
    /*Recursive Sol*/
    // return solve(num, tar, 3);

    /*Memoisation*/
    // vector<int> dp(tar + 1, -1);
    // return solve2(num, tar, 3, dp);

    /*Tabulation*/
    return solve3(num, tar, 3);
}

int main(){

    vector<int> arr = {1, 2, 5};
    int target = 5;

    cout << findWays(arr, target) << endl;
    
    return 0;
}