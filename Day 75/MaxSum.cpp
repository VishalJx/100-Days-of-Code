#include <bits/stdc++.h>
using namespace std;

/*RECURSION*/
// int solve(int arr[] ,int n){
//     if(n == 0){
//         return 0;
//     }
//     if(n < 0){
//         return arr[0];
//     }

//     int include = solve(arr, n-2) + arr[n];
//     int exclude = solve(arr, n-1);

//     return max(include, exclude);

// }

/*MEMOISATION*/
// int solve2(int arr[], int n, int dp[]){
//     if(n == 0){
//         return 0;
//     }
//     if(n < 0){
//         return arr[0];
//     }

//     if(dp[n] != -1){
//         return dp[n];
//     }

//     int include = solve2(arr, n-2, dp) + arr[n];
//     int exclude = solve2(arr, n-1, dp);

//     return dp[n] = max(include, exclude);
// }


/*TABULATION*/
int solve3(int arr[], int n){
    vector<int> dp(n, 0);
    dp[0] = arr[0];

    for(int i = 1; i < n; i++){
        int include = dp[i-2] + arr[i];
        int exclude = dp[i-1];
        dp[i] = max(include, exclude);
    }

    return dp[n-1];
}

int maxSumOfNonAdjadecent(int arr[], int n){
    int ans = solve(arr, n-1);
    return ans;
}

int main(){
    int arr[] = {5, 5, 10, 100, 10, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << maxSumOfNonAdjadecent(arr, n) << endl;
    
    return 0;
}