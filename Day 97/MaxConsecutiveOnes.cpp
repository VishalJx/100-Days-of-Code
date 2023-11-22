#include <bits/stdc++.h>
using namespace std;

int longestSubSeg(vector<int> &nums , int n, int k){

    int ans = 0, cnt = 0;
    int j = -1;

    for (int i = 0; i < n; ++i)
    {
        if (nums[i] == 0) cnt++;
        while (cnt > k) {
            j++;
            if (nums[j] == 0) cnt--;
        }

        int len = i - j;
        if (len > ans) ans = len;
    }

    return ans;
}

int main(){

    vector<int> nums = {1,1,0,1,0,1};
    int n = nums.size();
    int k = 1;

    cout << longestSubSeg(nums, n, k) << endl;
    
    return 0;
}