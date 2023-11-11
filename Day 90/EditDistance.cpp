#include <bits/stdc++.h>
using namespace std;

// Recursive Solution
// int solve(string word1, string word2, int i, int j){
//     if(i == word1.size() && j == word2.size()){
//         return 0;
//     }
//     if(i == word1.size()){
//         return word2.size() - j;
//     }
//     if(j == word2.size()){
//         return word1.size() - i;
//     }
//     if(word1[i] == word2[j]){
//         return solve(word1, word2, i + 1, j + 1);
//     }
//     int insert = 1 + solve(word1, word2, i, j + 1);
//     int remove = 1 + solve(word1, word2, i + 1, j);
//     int replace = 1 + solve(word1, word2, i + 1, j + 1);
//     return min(insert, min(remove, replace));
// }

// Memoization
int solve2(string word1, string word2, int i, int j, vector<vector<int>> &dp){
    if(i == word1.size() && j == word2.size()){
        return 0;
    }
    if(i == word1.size()){
        return word2.size() - j;
    }
    if(j == word2.size()){
        return word1.size() - i;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(word1[i] == word2[j]){
        return dp[i][j] = solve2(word1, word2, i + 1, j + 1, dp);
    }
    int insert = 1 + solve2(word1, word2, i, j + 1, dp);
    int remove = 1 + solve2(word1, word2, i + 1, j, dp);
    int replace = 1 + solve2(word1, word2, i + 1, j + 1, dp);
    return dp[i][j] = min(insert, min(remove, replace));
}

int minDistance(string word1, string word2){
    /*Recursive Sol*/
    // return solve(word1, word2, 0, 0);

    /*Memoization*/
    // vector<vector<int>> dp(word1.size() , vector<int>(word2.size(), -1));
    // return solve2(word1, word2, 0, 0, dp);
}

int main(){

    string word1 = "horse";
    string word2 = "ros";
    cout << minDistance(word1, word2) << endl;
    
    return 0;
}