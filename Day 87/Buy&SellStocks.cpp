#include <bits/stdc++.h>
using namespace std;

//Easy variant
//-> You can buy and sell only once

int maxProfit(vector<int>& prices) {
    int mini = prices[0];
    int profit = 0;
    for(int i=1;i<prices.size();i++){
        int diff = prices[i]-mini;
        profit = max(profit,diff);
        mini = min(mini,prices[i]);
    }
    return profit;
}

int main(){
    
    vector<int> prices = {7,1,5,3,6,4};
    cout<<maxProfit(prices)<<endl;

    return 0;
}