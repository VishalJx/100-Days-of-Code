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

//construct BST using level order traversal
Node* buildFromLevelOrder(Node* root){
    queue<Node*> q;

    //for root node
    int data;
    cout <<"Enter the root node data"<<endl;
    cin >> data;
    root = new Node(data);
    q.push(root);

    //for other nodes
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        int leftData;
        cout <<"Enter the left child of "<<temp -> data<<endl;
        cin >> leftData;
        if(leftData != -1) {
            temp -> left = new Node(leftData);
            q.push(temp -> left);
        }

        int rightData;
        cout <<"Enter the right child of "<<temp -> data<<endl;
        cin >> rightData;
        if(rightData != -1) {
            temp -> right = new Node(rightData);
            q.push(temp -> right);
        }
    }
    return root;

}

bool isBST(Node* root, int MIN, int MAX){
    if(root == NULL){
        return true;
    }
    if(root->data > MIN && root->data < MAX && isBST(root->left, MIN, root->data) && isBST(root->right, root->data, MAX)){
        return true;
    }
    return false;
}

bool validBST(Node* root){
    return isBST(root, INT_MIN, INT_MAX);
}

int main(){

    Node* root = NULL;
    root = buildFromLevelOrder(root);
    cout<<validBST(root)<<endl;
    
    return 0;
}