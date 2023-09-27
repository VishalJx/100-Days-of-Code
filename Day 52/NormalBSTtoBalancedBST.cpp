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

//creating bst using level order traversal
Node *buildFromLevelOrder(Node *root){
    queue<Node *> q;
    // for root node
    int data;
    cout << "Enter the root node data" << endl;
    cin >> data;
    root = new Node(data);
    q.push(root);

    // for other nodes
    while (!q.empty()){
        Node *temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter the left child of " << temp->data << endl;
        cin >> leftData;
        if (leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout << "Enter the right child of " << temp->data << endl;
        cin >> rightData;
        if (rightData != -1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
    return root;
}

//inorder traversal: which will give us the sorted array
void inorder(Node *root, vector<int> &in){
    if (root == NULL)
        return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

//converting inorder to balanced bst
//using algorithm of binary search
Node *inorderTobalancedBST(vector<int> &in, int start, int end){
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    //creating root node
    Node *root = new Node(in[mid]);
    //creating left and right subtree
    root->left = inorderTobalancedBST(in, start, mid - 1);
    root->right = inorderTobalancedBST(in, mid + 1, end);
    return root;
}

//function to convert normal bst to balanced bst
Node *normalBSTtoBalancedBST(Node *root){
    //first we will store the inorder traversal of the bst in a vector
    vector<int> in;
    inorder(root, in);
    //now we will convert the inorder vector to balanced bst
    return inorderTobalancedBST(in, 0, in.size() - 1);
}


int main(){
    Node *root = NULL;
    root = buildFromLevelOrder(root);
    root = normalBSTtoBalancedBST(root);
    
    return 0;
}