//Left data < root data < right data

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

Node* insertInBST(Node* &root, int val){
    //Base Case
    if(root == NULL){
        root = new Node(val);
        return root;
    }
    //Recursive Case
    //Insert in left subtree
    if(val < root->data){
        root->left = insertInBST(root->left, val);
    }
    //Insert in right subtree
    else{
        root->right = insertInBST(root->right, val);
    }
    return root;
}

//taking input from user
void takeInput(Node* &root){
    int data;
    cin>>data;

    //until user enters -1, keep inserting in BST
    while(data != -1){
        root = insertInBST(root, data);
        cin>>data;
    }
}

void printInorder(Node* root){
    //Base Case
    if(root == NULL){
        return;
    }
    //Recursive Case
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

void levelOrderPrint(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
}

int main(){
    Node* root = NULL;

    cout<<"Enter data to create BST:"<<endl;
    takeInput(root);

    cout<<"Inorder Traversal of BST:"<<endl;
    printInorder(root);

    cout<<endl<<"Level Order Traversal of BST:"<<endl;
    levelOrderPrint(root);
    
    return 0;
}