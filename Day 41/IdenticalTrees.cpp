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

bool isIdentical(Node* root1, Node* root2){
    //both are null
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    //both are not null
    else if(root1 == NULL || root2 == NULL){
        return false;
    }
    else{
        bool cond1 = root1->data == root2->data;
        bool cond2 = isIdentical(root1->left, root2->left);
        bool cond3 = isIdentical(root1->right, root2->right);

        if(cond1 && cond2 && cond3){
            return true;
        }
        else{
            return false;
        }
    }
}

int main(){

    Node root1* = NULL;
    Node root2* = NULL;

    return 0;
}

