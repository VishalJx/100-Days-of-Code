#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = NULL;
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

//converting the sorted array to linked list
Node *flattenBST(Node *root){
    vector<int> in;
    //store the inorder traversal in the vector
    inorder(root, in);

    //here, this is the new root of the linked list
    Node* newRoot = new Node(in[0]);
    //this is the current pointer
    Node* current = newRoot;
    //now, we will connect the nodes
    for (int i = 1; i < in.size(); i++){
        Node *temp = new Node(in[i]);

        current->left = NULL; //making the left pointer NULL
        current->right = temp; //connecting the nodes
        current = temp; //updating the current pointer
    }
    //making the last node's left and right pointer NULL
    current -> left = NULL; //making the last node's left pointer NULL
    current -> right = NULL; //making the last node's right pointer NULL

    return newRoot;//returning answer
}

//printing the linked list
void printList(Node *head){
    Node *temp = head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->right;
    }
}

int main(){
    Node *root = NULL;
    root = buildFromLevelOrder(root);

    Node *head = flattenBST(root);
    printList(head);
    
    return 0;
}