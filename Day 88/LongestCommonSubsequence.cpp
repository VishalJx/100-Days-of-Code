#include <bits/stdc++.h>
using namespace std;

/*Recursive SOlution*/
// int solve(string s1, string s2, int i, int j){
//     //base case
//     if(i==s1.size() || j==s2.size()){
//         return 0;
//     }
//     int ans = 0;
//     if(s1[i]==s2[j]){
//         ans = 1 + solve(s1,s2,i+1,j+1);
//     }
//     else{
//         int op1 = solve(s1,s2,i+1,j);
//         int op2 = solve(s1,s2,i,j+1);
//         ans = max(op1,op2);
//     }
//     return ans;
// }

/*Memoisation*/
int solve2(string s1, string s2, int i, int j, vector<vector<int>>& dp){
    //base case
    if(i==s1.size() || j==s2.size()){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans = 0;
    if(s1[i]==s2[j]){
        ans = 1 + solve2(s1,s2,i+1,j+1,dp);
    }
    else{
        int op1 = solve2(s1,s2,i+1,j,dp);
        int op2 = solve2(s1,s2,i,j+1,dp);
        ans = max(op1,op2);
    }
    return dp[i][j] = ans;
}

int longestCommonSubsequence(string text1, string text2) {
    /*Recursive Sol*/
    // return solve(text1,text2, 0, 0);

    /*Memoisation*/
    vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
    return solve2(text1,text2, 0, 0, dp);
}

int main(){
    string s1 = "abcdgh";
    string s2 = "abedfhr";

    cout<<longestCommonSubsequence(s1,s2)<<endl;

    return 0;
}