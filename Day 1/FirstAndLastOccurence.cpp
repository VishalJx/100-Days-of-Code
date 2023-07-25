#include <bits/stdc++.h>
using namespace std;

int leftMostOccurence(int arr[], int size, int key){
    int start = 0, end = size;
    int mid = (start + (end - start)/2);
    int answer; //This is the value where first encountered index of key is saved
    while(start <= end){
        if(arr[mid] == key){
            answer = mid; //In case we find answer at mid, then let's store it 
                        //and check if any other same element exists on left-hand side(since checking first occurence).

            end = mid - 1; //to shift from mid to left side of array
        }
        else if(arr[mid] > key){
            end = mid - 1;
        }
        else if(arr[mid] < key){
            start = mid + 1;
        }
        mid = (start + (end - start)/2);
    }
    return answer;
}

int RightMostOccurence(int arr[], int size, int key){
    int start = 0, end = size;
    int mid = (start + (end - start)/2);
    int answer;
    while(start <= end){
        if(arr[mid] == key){
            answer = mid; //In case we find answer at mid, then let's store it 
                        //and check if any other same element exists on right-hand side(since checking last occurence).
            start = mid + 1; //to shift from mid to right side of array
        }
        else if(arr[mid] > key){
            end = mid - 1;
        }
        else if(arr[mid] < key){
            start = mid + 1;
        }
        mid = (start + (end - start)/2);
    }
    return answer;
}

int main()
{
    int arr[6] = {1,2,3,3,5,12};
    int key = 3;
    int index1 = leftMostOccurence(arr, 6, key);
    int index2 = RightMostOccurence(arr, 6, key);

    cout <<"Left most occurence index of "<<key<<" is "<<index1<<endl;
    cout <<"Right most occurence index of "<<key<<" is "<<index2;
    return 0;
}

/*NOTE:
    Left most occurence is the first position of the key
    Right most occurence is the last position of the key
*/
/*IMPLEMENTATION
    We can count the number occurence of an elements in a sorted array.
    i.e. (LastOccurence - FirstOccurence);
    Otherwise it would take O(n) time complexity if we do it with linear search.
*/



/*
LEETCODE SOLUTION:-

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        vector<int> ans = {-1, -1};

        // Binary search to find the first occurrence of the target
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                ans[0] = mid;
                end = mid - 1; // Move left to find any other left (first) occurrence
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        // Reset the start and end pointers for the second binary search
        start = 0;
        end = nums.size() - 1;

        // Binary search to find the last occurrence of the target
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                ans[1] = mid;
                start = mid + 1; // Move right to find any other right (last) occurrence
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};


*/