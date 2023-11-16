#include <bits/stdc++.h>
using namespace std;

/*Brute Force*/ // --> O(n^2)
vector<int> solve1(vector<int>& nums, int target){
    vector<int> ans;
    //first loop will visit all the elements
    for(int i = 0; i < nums.size(); i++){
        //second loop will visit all the elements after the ith element
        for(int j = i + 1; j < nums.size(); j++){
            //if the sum of the two elements is equal to the target
            if(nums[i] + nums[j] == target){
                //push the indices in the ans vector
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}

/*Optimal-> using hashmap*/
vector<int> solve2(vector<int>& nums, int target){
    vector<int> ans;
    //create a hashmap
    unordered_map<int, int> mp;
    //iterate over the array
    for(int i = 0; i < nums.size(); i++){
        //if the target - nums[i] is present in the hashmap
        if(mp.find(target - nums[i]) != mp.end()){
            //push the indices in the ans vector
            ans.push_back(mp[target - nums[i]]);
            ans.push_back(i);
            return ans;
        }
        //else add the element in the hashmap
        mp[nums[i]] = i;
    }

    return ans;

}


vector<int> twoSum(vector<int>& nums, int target){

    /*Brute Force*/
    // return solve1(nums, target);

    /*Optimal*/
    return solve2(nums, target);

}

int main(){

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = twoSum(nums, target);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    
    return 0;
}