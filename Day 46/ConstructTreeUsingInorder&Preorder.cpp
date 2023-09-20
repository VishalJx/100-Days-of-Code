#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int data){
            this->data = data;
            left = right = NULL;
        }
};

//Inorder: Left, Root, Right(at root we print)
//[1 6 8 7]
//Preorder: Root, Left, Right(at root we print)
//[1 6 7 8]
//0th index of preorder is root of the tree

//find the position of the element in inorder array
int findPosition(int in[], int element, int n){
    for(int i=0; i<n; i++){
        if(in[i] == element){
            return i;
        }
    }
    return -1;
}

Node* solve(int in[], int pre[], int inorderStart, int inorderEnd, int size, int &preOrderIndex){
    //base case
    //covered whole array of preorder
    if(preOrderIndex>=size || inorderStart > inorderEnd){
        return NULL;
    }

    int element = pre[preOrderIndex++];
    Node* root = new Node(element);
    //
    int position = findPosition(in, element,size);

    //recursion(only change in start and end of inorder array)
    root->left = solve(in, pre, inorderStart, position-1, size, preOrderIndex);
    root->right = solve(in, pre, position+1, inorderEnd, size, preOrderIndex);

    return root;

}

Node* buildTree(int in[], int pre[], int n){
    int preOrderIndex = 0; //root of the tree itself
    Node* ans = solve(in, pre, 0, n-1, n, preOrderIndex);
    return ans;
}

//printing the tree
void print(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

int main(){

    int in[] = {1, 6, 8, 7};
    int pre[] = {1, 6, 7, 8};
    int n = 4;

    Node* root = buildTree(in, pre, n);
    print(root);
    
    return 0;
}