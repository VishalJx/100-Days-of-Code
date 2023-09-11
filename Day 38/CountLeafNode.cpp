#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            this->left = NULL;
            this->right = NULL;
        }
};

//Building a tree: Using Level Order Traversal
Node* buildFromLevelOrder(Node* root){
    queue<Node*> q;

    //for root node
    int data;
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

//Using any traversal to traverse tree
void inorderTraversal(Node* root, int count){
    if(root == NULL) 
        return;
    inorderTraversal(root -> left, count);
    if(root -> left == NULL && root -> right == NULL){
        count++;
        cout << root -> data << " ";
    }
    inorderTraversal(root -> right, count);
}

//Counting the number of leaf nodes
int leafCount(Node* root){
    int count = 0;
    inorderTraversal(root, count);
    return count;
}
 
int main() {
    Node* root = NULL;
    root = buildFromLevelOrder(root);
    cout<<leafCount(root);
    return 0;
}   