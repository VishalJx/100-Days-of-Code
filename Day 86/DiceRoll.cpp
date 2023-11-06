#include <bits/stdc++.h>
using namespace std;

/*Recursive Sol*/
// long long solve(int dice, int face, int target){
//     //Base Case
//     if(target<0)
//         return 0;
//     if(dice==0 && target != 0)
//         return 0;
//     if(dice!=0 && target == 0)
//         return 0;
//     if(dice==0 && target == 0)
//         return 1;
    
//     long long ans = 0;
//     for(int i = 1; i<=face; i++){
//         ans = ans + solve(dice-1, face, target-i);
//     }
//     return ans;

// }

long long solve2(int dice, int face, int target, vector<vector<long long>> &dp){
    //Base Case
    if(target<0)
        return 0;
    if(dice==0 && target != 0)
        return 0;
    if(dice!=0 && target == 0)
        return 0;
    if(dice==0 && target == 0)
        return 1;
    
    if(dp[dice][target] != -1)
        return dp[dice][target];
    
    long long ans = 0;
    for(int i = 1; i<=face; i++){
        ans = ans + solve2(dice-1, face, target-i, dp);
    }
    return dp[dice][target] = ans;

}

long long noOfWays(int dice, int face, int target){
    /*Recursive sol*/
    // return solve(dice, face, target);

    /*Memoization*/ // 2d DP
    vector<vector<long long>> dp(dice+1, vector<long long>(target+1, -1));
    return solve2(dice, face, target, dp);
}   

int main(){

    cout<<noOfWays(6, 3, 12)<<endl;
    
    return 0;
}