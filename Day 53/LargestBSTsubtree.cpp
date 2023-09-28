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

class info{
    public:
        int size;
        int max;
        int min;
        bool isBST;
};

info solve(Node* root, int &ans){
    // Base case
    if(root == NULL){
        return {0, INT_MIN, INT_MAX, true};
    }
    // Leaf node
    info leftInfo = solve(root->left, ans);
    // right node
    info rightInfo = solve(root->right, ans);

    info currNode;
    currNode.size = (1 + leftInfo.size + rightInfo.size); // size of subtree
                                                        // 1 for root node
    currNode.max = max(root->data, max(leftInfo.max, rightInfo.max));

    currNode.min = min(root->data, min(leftInfo.min, rightInfo.min));

    if(leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && rightInfo.min > root->data){
        currNode.isBST = true;
        ans = max(ans, currNode.size);
    }
    else{
        currNode.isBST = false;
    }
    //update ans
    if(currNode.isBST){
        ans = max(ans, currNode.size);
    }
    return currNode;
}

int largestBST(Node* root){
    int maxSize = 0;
    info rootInfo = solve(root, maxSize);
    return maxSize;
}

int main(){
    Node* root = NULL;
    
    return 0;
}


