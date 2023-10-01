#include <bits/stdc++.h>
using namespace std;

//for BT
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

/* Conditions to be heap
    1. It should be a complete binary tree.
    2. It should follow heap property.
        a. Max Heap: Every node is greater than its children.
        b. Min Heap: Every node is smaller than its children.
*/

//is complete binary tree
bool isCBT(Node* root, int index, int count){
    //base case
    if(root == NULL){
        return true;
    }
    if(index > count){
        return false;
    }
    //recursive case
    //left
    bool left = isCBT(root->left, 2*index, count);
    //right
    bool right = isCBT(root->right, 2*index+1, count);

    return left && right;

}

//is max heap
bool isMaxOrder(Node* root){
    //base case
    if(root == NULL){
        return true;
    }
    //recursive case
    bool left = isMaxOrder(root->left);
    bool right = isMaxOrder(root->right);

    if(left && right){
        //for leaf node
        if(root->left == NULL && root->right == NULL){
            return true; //leaf node is always a heap
        }
        else if(root->left == NULL){
            return root->data > root->right->data;
        }
        else if(root->right == NULL){
            return root->data > root->left->data;
        }
        else{
            return root->data > root->left->data && root->data > root->right->data;
        }
    }
    return false;
}

//count node
//count number of nodes in a tree
int countNode(Node* root){
    //base case
    if(root == NULL){
        return 0;
    }
    //recursive case
    return 1/*root*/ + countNode(root->left)/*Left*/ + countNode(root->right)/*right*/;
}

//is heap
bool isHeap(Node* root){
    int index = 0;
    int totalNodes = countNode(root);
    if(isCBT(root, index, totalNodes) && isMaxOrder(root)){
        return true;
    }
    return false;

     
}

int main(){
    
    return 0;
}