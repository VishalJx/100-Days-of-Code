#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};

// construct BST using level order traversal
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

//NOTE : Inorder traversal of BST gives sorted array
//Hence, we can find kth smallest element by finding kth element in inorder traversal

//below is inorder traversal of BST
int solve(Node *root, int &counter, int k){
    //base case
    if(root == NULL){
        return -1;
    }
    //recursive case
    //left(l)
    int left = solve(root->left, counter, k);
    if(left != -1){
        return left;
    }

    //root(N)
    counter++;
    //answer found
    if(counter == k){
        return root->data;
    }

    //right(R)
    int right = solve(root->right, counter, k);
    if(right != -1){
        return right;
    }
}

//counter is keeping track of the number of nodes visited
int kthSmallestElement(Node *root,int counter, int k){
    int ans = solve(root,counter, k);
    return ans;
}

int main(){
    Node *root = NULL;
    root = buildFromLevelOrder(root);

    int k;
    cout << "Enter the value of k" << endl;
    cin >> k;

    int counter = 0;
    int ans = kthSmallestElement(root, counter, k);
    cout << "The" <<k<<"th"<< "smallest element is " << ans << endl;
    
    return 0;
}