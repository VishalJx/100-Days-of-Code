//Height or Depth of a Binary Tree
//Definition: Longest path between root node and leaf node.

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val) {
            data = val;
            left = NULL;
            right = NULL;
        }
};

//creating a binary tree: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
Node* buildTree(Node* root) {
    int d;
    cout << "Enter the data: "<<endl;
    cin >> d;

    if(d == -1) {
        return NULL;
    }

    root = new Node(d);
    cout << "Enter the left child of "<<d<<endl;
    root -> left = buildTree(root -> left);
    cout << "Enter the right child of "<<d<<endl;
    root -> right = buildTree(root -> right);

    return root;
}

//Height of a binary tree
int height(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}


int main() {
    Node* root = NULL;
    root = buildTree(root);
    cout<<"Height is: "<<height(root)<<endl;

    return 0;
}