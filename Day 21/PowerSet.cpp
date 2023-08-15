#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans){
    
        if(index >= nums.size()){ // base case:here index is the size of the vector nums
            ans.push_back(output); // pushing the output vector to the answer vector
            return;
        }

        //excluding
        solve(nums, output, index+1, ans); // not including the current element(basically skipping that element)
        
        //including
        output.push_back(nums[index]); // including the current element
        solve(nums, output, index+1, ans); // going to next element
}

vector<vector<int>> powerSet(vector<int> &nums){

    vector<vector<int>> ans; // to store the answer in the form of vector of vector
    vector<int> output; // to store the output of each recursive call
    solve(nums, output, 0, ans); // calling the recursive function
    return ans;

}
 
int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = powerSet(nums);
    for(int i=0; i<result.size(); i++){ //row traversal
        for(int j=0; j<result[i].size(); j++){ //column traversal
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

/*Working of above code in steps
1. Initially, the output vector is empty and the index is 0.
2. The first recursive call is made by excluding the first element of the vector nums,
     hence the output vector is empty.
3. The second recursive call is made by including the first element of the vector nums,
     hence the output vector is {1}.
4. The third recursive call is made by excluding the second element of the vector nums,
     hence the output vector is {1}.
5. The fourth recursive call is made by including the second element of the vector nums,
    hence the output vector is {1, 2}.
6. The fifth recursive call is made by excluding the third element of the vector nums,
    hence the output vector is {1, 2}.
7. The sixth recursive call is made by including the third element of the vector nums,
    hence the output vector is {1, 2, 3}.
8. The seventh recursive call is made by excluding the fourth element of the vector nums,
    hence the output vector is {1, 2, 3}.
9. The base case is reached, hence the output vector {1, 2, 3} is pushed to the answer vector.
*/