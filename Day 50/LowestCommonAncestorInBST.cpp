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

//we know that inorder traversal of a BST is always sorted
//also left subtree is always smaller than root and right subtree
//is always greater than root
Node *lca(Node *root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data > n1 && root->data > n2){
        return lca(root->left, n1, n2);
    }

    if(root->data < n1 && root->data < n2){
        return lca(root->right, n1, n2);
    }

    return root;
}


int main(){
    
    return 0;
}