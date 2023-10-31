#include <bits/stdc++.h>
using namespace std;

/*RECURSIVE SOLUTION*/
int solve(vector<int> weight, vector<int> value, int lastIndex, int maxWeight){
    //Base Case
    //if only 1 item to steal, then compare its wright with maxWeight(knapsack capacity)
    if(lastIndex == 0){
        if(weight[lastIndex] <= maxWeight){
            return value[lastIndex];
        }
        else{
            return 0;
        }
    }
    /*Using include/exclude approach since we need to find max combination*/

    //include
    int include = 0;
    if(weight[lastIndex] <= maxWeight){
        include = value[lastIndex] + solve(weight, value, lastIndex-1, maxWeight-weight[lastIndex]);
    }
    //exclude
    int exclude = 0 + solve(weight, value, lastIndex-1, maxWeight);

    return max(include, exclude);
}


/*MEMOISATION*/
// int solve1(vector<int> weight, vector<int> value, int lastIndex, int maxWeight, vector<vector<int>> &dp){
//     //Base Case
//     //if only 1 item to steal, then compare its wright with maxWeight(knapsack capacity)
//     if(lastIndex == 0){
//         if(weight[lastIndex] <= maxWeight){
//             return value[lastIndex];
//         }
//         else{
//             return 0;
//         }
//     }

//     //since two variables are changing, we need 2d dp
//     if(dp[lastIndex][maxWeight] != -1){
//         return dp[lastIndex][maxWeight];
//     }

//     /*Using include/exclude approach since we need to find max combination*/

//     //include
//     int include = 0;
//     if(weight[lastIndex] <= maxWeight){
//         include = value[lastIndex] + solve1(weight, value, lastIndex-1, maxWeight-weight[lastIndex], dp);
//     }
//     //exclude
//     int exclude = 0 + solve1(weight, value, lastIndex-1, maxWeight,dp);

//     return max(include, exclude);
// }

/*TABULATION*/
int solve2(vector<int weight, vector<int> value, int n, int maxWeight ){
    //step 1
    vector<vector<int>> dp(n+1, vector<int>(maxWeight+1, 0));

    //step 2: base case analysis
    for(int w = weight[0]; w <= maxWeight; w++){
        if(weight[0] <= maxWeight){
            dp[0][w] = value[0];
        }
        else{
            dp[0][w] = 0;
        }
    }

    for(int index = 1; index < n; index++){
        for(int w = 1; w <= maxWeight; w++){
            //include
            int include = 0;
            if(weight[index] <= w){
                include = value[index] + dp[index-1][w-weight[index]];
            }
            //exclude
            int exclude = 0 + dp[index-1][w];

            dp[index][w] = max(include, exclude);
        }
    }

    return dp[n-1][maxWeight];
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
    /*Recursive Solution*/
    // return solve(weight, value, n-1, maxWeight);

    /*Memoisation*/
    // vector<vector<int>> dp(n+1, vector<int>(maxWeight+1, -1));
    // return solve1(weight, value, n-1, maxWeight, dp);

}



int main(){

    vector<int> weight = {1, 2, 3, 5};
    vector<int> value = {1, 6, 10, 16};

    int n = 4;

    int maxWeight = 7;

    cout<<knapsack(weight, value, n, maxWeight)<<endl;
    
    return 0;
}