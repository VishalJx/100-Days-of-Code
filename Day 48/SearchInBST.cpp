#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};

//recursive function to search in BST
bool searchInBST(Node* root, int key){
    //Base Case
    if(root == NULL){
        return false;
    }
    //Recursive Case
    if(root->data == key){
        return true;
    }
    //search in left subtree
    if(key < root->data){
        return searchInBST(root->left, key);
    }
    //search in right subtree
    else{
        return searchInBST(root->right, key);
    }
}

//iterative function to search in BST
bool searchInBSTIterative(Node* root, int key){

    while(root != NULL){
        if(root->data == key){
            return true;
        }
        else if(key < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return false;
}

int main(){
    
    return 0;
}