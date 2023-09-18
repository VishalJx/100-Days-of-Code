#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};

void solve(Node* root, int k, vector<int> &path, int &count){
    // base case
    if(root == NULL){
        return;
    }
    // recursive case
    path.push_back(root->data);// push the current node in the path
    solve(root->left, k, path, count); // call for left subtree
    solve(root->right, k, path, count); // call for right subtree

    // check for the path with sum k
    int sum = 0;
    for(int i = path.size()-1; i >= 0; i--){ // traverse the path from the end
        sum += path[i];
        if(sum == k){
            count++;
        }
    }
    path.pop_back();// remove the current node from the path
                    // to backtrack to the parent node
                    //at the end we have all the paths from root to leaf    
                    //hence while backtracking we remove the nodes from the path
}

// Time Complexity: O(N^2)
int kSumPath(Node* root, int k){
    vector<int> path;
    int count = 0;
    solve(root, k, path, count);
    return count;
}

int main(){

    Node* root = NULL;
    int sol = kSumPath(root, 5);
    cout << sol << endl;
    
    return 0;
}