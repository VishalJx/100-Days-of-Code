#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;

        Node(int data){
            this->data = data;
            left = right = NULL;
        }
};

pair<int,int> solve(Node* root){
    if(root == NULL){
        return {0,0};
    }
    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> res;
    res.first = root->data + left.second + right.second;
    res.second = max(left.first, left.second) + max(right.first, right.second);

    return res;
}

int maxSum(Node *root){
    pair<int, int> res = solve(root);
    return max(res.first, res.second);
}

int main(){
    
    return 0;
}