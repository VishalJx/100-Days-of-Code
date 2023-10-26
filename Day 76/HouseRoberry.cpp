#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int> &nums){
    int n = nums.size();

    long long int prev2 = 0;
    long long int prev1 = nums[0];

    for(int i=1; i<n; i++){
        long long int curr = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

long long houseRobbery(vector<int> &valueInHouse){
    int n = valueInHouse.size();

    if(n == 1){
        return valueInHouse[0];
    }

    vector<int> first, second;
    for(int i=0; i<n; i++){
        if(i != n-1)
            first.push_back(valueInHouse[i]);
        if(i != 0)
            second.push_back(valueInHouse[i]);
    }
    return max(solve(first), solve(second));

}

int main(){

    vector<int> valueInHouse = {1, 2, 3, 1};
    cout<<houseRobbery(valueInHouse)<<endl;
    
    return 0;
}