#include <bits/stdc++.h>
using namespace std;

//Brute Force --> O(n^2)
void sort012(vector<int>& nums, int n){
    for(int i = 0; i<=n; i++){
        for(int j = i+1; j<=n; j++){
            if(nums[i] > nums[j]){
                swap(nums[i], nums[j]);
            }
        }
    }
}

//Optimal --> O(n)
//Dutch National Flag Algorithm
void sort012(vector<int>& nums, int n){
    int low = 0, mid = 0, high = n-1;
    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid] == 1){
            mid++;
        }
        else{
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}


int main(){

    vector<int> nums = {2, 0, 2, 1, 1, 0};
    int n = nums.size();

    sort012(nums, n);

    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    return 0;
}