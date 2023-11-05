#include <bits/stdc++.h>
using namespace std;

/*Recursive Sol*/
// int solve(vector<int> &A, int i, int j){
//     // Base Case
//     if(i+1 == j) 
//         return 0;
    
//     int ans = INT_MAX;
//     for(int k=i+1; k<j; k++){
//         int temp = solve(A, i, k) + solve(A, k, j) + A[i]*A[j]*A[k];
//         ans = min(ans, temp);
//     }
//     return ans;
// }

/*Memoisation Sol*/
// int solve2(vector<int> &A, int i, int j, vector<vector<int>> &dp){
//     // Base Case
//     if(i+1 == j) 
//         return 0;
    
//     if(dp[i][j] != -1)
//         return dp[i][j];
    
//     int ans = INT_MAX;
//     for(int k=i+1; k<j; k++){
//         int temp = solve2(A, i, k, dp) + solve2(A, k, j, dp) + A[i]*A[j]*A[k];
//         ans = min(ans, temp);
//     }
//     return dp[i][j] = ans;
// }

/*Tabulation Sol*/
int solve3(vector<int> &A){
    int size = A.size();
    vector<vector<int>> dp(size, vector<int>(size, 0));

    for(int i = size-1; i>=0; i--){
        for(int j = i+2; j<size; j++){
            int ans = INT_MAX;
            for(int k=i+1; k<j; k++){
                int temp = dp[i][k] + dp[k][j] + A[i]*A[j]*A[k];
                ans = min(ans, temp);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][size-1];
}

int minScoreTriangulation(vector<int>& A) {
    /*Recursive Sol*/
    // int end = A.size()-1;
    // int ans = solve(A, 0, end);
    // return ans;

    /*Memoisation Sol*/ //2D DP
    // int size = A.size();
    // vector<vector<int>> dp(size, vector<int>(size, -1));
    // int ans = solve2(A, 0, size-1, dp);
    // return ans;

    /*Tabulation Sol*/ //2D DP
    int size = A.size();
    int ans = solve3(A);
    return ans;
}

int main(){

    vector<int> A = {1,2,3};
    int ans = minScoreTriangulation(A);
    
    return 0;
}