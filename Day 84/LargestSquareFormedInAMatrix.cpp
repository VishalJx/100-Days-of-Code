#include <bits/stdc++.h>
using namespace std;

/*RECURSIVE SOLUTION*/
// int solve(vector<vector<int>> mat, int i, int j, int &maxi){
//     if(i == mat.size() || j == mat[0].size()){
//         return 0;
//     }

//     int right = solve(mat, i, j+1, maxi);
//     int down = solve(mat, i+1, j, maxi);
//     int diag = solve(mat, i+1, j+1, maxi);

//     if(mat[i][j] == 1){
//         int ans = 1 + min(right, min(down, diag));
//         maxi = max(maxi, ans);
//         return ans;
//     }
//     else{
//         return 0;
//     }
// }

/*MEMOISATION*/
int solve2(vector<vector<int>> mat, int i, int j, int &maxi, vector<vector<int>> &dp){
    if(i == mat.size() || j == mat[0].size()){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int right = solve2(mat, i, j+1, maxi, dp);
    int down = solve2(mat, i+1, j, maxi, dp);
    int diag = solve2(mat, i+1, j+1, maxi, dp);

    if(mat[i][j] == 1){
        int ans = 1 + min(right, min(down, diag));
        maxi = max(maxi, ans);
        return dp[i][j] = ans;
    }
    else{
        return dp[i][j] = 0;
    }
}

int maxSquare(int n, int m, vector<vector<int>> mat){
    /*Recursive Sol*/
    // int maxi = 0;
    // solve(mat, 0, 0, maxi);
    // return maxi;

    /*Memoisation*/
    //2-d dp has to be applied
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxi = 0;
    solve2(mat, 0, 0, maxi, dp);
    return maxi;
}

int main(){
    
    return 0;
}