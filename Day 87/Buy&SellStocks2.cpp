#include <bits/stdc++.h>
using namespace std;

//Variation - 2
//- You can buy and sell as many times as you want

//Recursive Solution    
// int solve(int index, int isBuy, vector<int>& prices){
//     //base case
//     if(index==prices.size()){
//         return 0;
//     }
//     int profit = 0;
//     if(isBuy){
//         //can Buy or skip
//         int buy = -prices[index] + solve(index+1,0,prices);
//         int skip = 0 + solve(index+1,1,prices);
//         profit = max(buy,skip);
//     }
//     else{
//         //can Sell or skip
//         int sell = prices[index] + solve(index+1,1,prices);
//         int skip = 0 + solve(index+1,0,prices);
//         profit = max(sell,skip);
//     }
//     return profit;
// }


/*Memoisation*/
int solve2(int index, int isBuy, vector<int>& prices, vector<vector<int>>& dp){
    //base case
    if(index==prices.size()){
        return 0;
    }
    if(dp[index][isBuy]!=-1){
        return dp[index][isBuy];
    }
    int profit = 0;
    if(isBuy){
        //can Buy or skip
        int buy = -prices[index] + solve2(index+1,0,prices,dp);
        int skip = 0 + solve2(index+1,1,prices,dp);
        profit = max(buy,skip);
    }
    else{
        //can Sell or skip
        int sell = prices[index] + solve2(index+1,1,prices,dp);
        int skip = 0 + solve2(index+1,0,prices,dp);
        profit = max(sell,skip);
    }
    return dp[index][isBuy] = profit;
}

int maxProfit(vector<int>& prices) {
    /*Recursive Sol*/
    // return solve(0,1,prices);

    /*Memoisation*/
    vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
    return solve2(0,1,prices,dp);
}

int main(){

    vector<int> prices = {7,1,5,3,6,4};
    cout<<maxProfit(prices)<<endl;
    
    return 0;
}