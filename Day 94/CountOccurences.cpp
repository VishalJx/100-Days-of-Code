#include <bits/stdc++.h>
using namespace std;

//Brute Force --> O(n) using linear search
int solve(vector<int> &nums, int target){
    int count = 0;
    for(int i = 0; i<nums.size(); i++){
        if(nums[i] == target){
            count++;
        }
    }
    return count;
}


//Optimal --> O(logn) using binary search

//first occurence
int first(vector<int> &nums, int target){
    int start = 0, end = nums.size()-1, res = -1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(nums[mid] == target){
            res = mid;
            end = mid-1; //keep searching towards left
        }
        else if(nums[mid] > target){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return res;
}

int last(vector<int> &nums, int target){
    int start = 0, end = nums.size()-1, res = -1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(nums[mid] == target){
            res = mid;
            start = mid+1; //keep searching towards right
        }
        else if(nums[mid] > target){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return res;

}

int solve2(vector<int> &nums, int target){
    int firstOccurence = first(nums, target);
    int lastOccurence = last(nums, target);

    int ans = lastOccurence - firstOccurence + 1;
    return ans;
}


int countOccurence(vector<int> &nums, int target){
    //Brute force
    // return solve(nums, target);

    //Optimal
    return solve2(nums, target);

}

int main(){
    //Sorted Array
    vector<int> nums = {1,1,1,2,2,3,3};

    int target = 1;

    cout << countOccurence(nums, target); 
    
    return 0;
}