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

Node* solve(Node* root, int k, vector<Node*> &path, vector<Node*> &ans){
    // base case
    if(root == NULL){
        return NULL;
    }
    if(root->data == k){
        return root;
    }
    // recursive case
    Node* left = solve(root->left, k, path, ans);
    Node* right = solve(root->right, k, path, ans);

    //backtracking
    if(left != NULL || right == NULL){
        k--;
        if(k <= 0){
            //answer lock
            k = INT_MAX;
            return root;
        }
        return left;
    }
    if(right != NULL || left == NULL){
        k--;
        if(k <= 0){
            //answer lock
            k = INT_MAX;
            return root;
        }
        return right;
    }
    return NULL;
}

int kthAncestor(Node* root, int k, int node){

    Node* ans = solve(root, k, node);
    if(ans == NULL){
        return -1;
    }
    return ans->data;
}

int main(){

    Node* root = NULL;
    int ans = kthAncestor(root, 2, 4);
    cout<<ans<<endl;
    
    return 0;
}