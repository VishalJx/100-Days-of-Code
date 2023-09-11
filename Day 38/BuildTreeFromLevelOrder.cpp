#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        //Constructor
        Node(int val) {
            this -> data = val;
            this -> left = NULL;
            this -> right = NULL;
        }
};

//Building a tree: Using Level Order Traversal
/*
     1
   /   \
  3     5
 / \    /   
7  11  17
    
*/
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
 
int main() {

    Node* root = NULL;
    root = buildFromLevelOrder(root);

    return 0;
}