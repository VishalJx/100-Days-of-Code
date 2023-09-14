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

pair <bool, int> isSumTree(Node* root){
    //base case
    if(root == NULL){
        pair <bool, int> p;
        //make_pair(p.first, p.second)
        p.first = true;
        p.second = 0;
        return p;
    }

    if(root->left == NULL && root->right == NULL){
        pair <bool, int> p;
        p.first = true;
        p.second = root->data;
        return p;
    }

    pair <bool, int> leftAns = isSumTree(root->left);
    pair <bool, int> rightAns = isSumTree(root->right);

    bool cond1 = root->data == leftAns.second + rightAns.second;

    pair <bool, int> ans;
    if(cond1 && leftAns.first && rightAns.first){
        ans.first = true;
        ans.second = 2 * root->data;
    }
    else{
        ans.first = false;
        ans.second = 0;
    }
    return ans;
}

int main(){

    Node* root1 = NULL;
    
    return 0;
}