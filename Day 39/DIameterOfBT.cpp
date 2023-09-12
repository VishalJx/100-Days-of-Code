//Diameter or Width of a Binary Tree
//the longest path between any two end nodes in a tree

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val) {
            data = val;
            left = NULL;
            right = NULL;
        }
};

Node* buildFromLevelOrder(Node* root){
    queue<Node*> q;

    //for root node
    int data;
    cout<<"Enter the node data: "<<endl;
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

//Height of a binary tree
int height(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

//Diameter of a binary tree: O(n^2)
int diameter(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int currDiameter = leftHeight + rightHeight + 1;

    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);

    return max(currDiameter, max(leftDiameter, rightDiameter));
}

//Optimized Diameter of a binary tree: O(n)
pair <int, int> optimizedDiameter(Node* root) {
    if(root == NULL) {
        pair<int, int> p;
        p.first = p.second = 0;
        return p;
    }

    pair<int, int> leftPair = optimizedDiameter(root->left);
    pair<int, int> rightPair = optimizedDiameter(root->right);

    pair<int, int> currPair;
    currPair.first = max(leftPair.first, rightPair.first) + 1;
    currPair.second = max(leftPair.first + rightPair.first, max(leftPair.second, rightPair.second));

    return currPair;
}

int main() {
    Node* root = NULL;
    root = buildFromLevelOrder(root);
    cout<<"Diameter is: "<<diameter(root)<<endl;
    cout<<"Optimized Diameter is: "<<optimizedDiameter(root).second<<endl;  

    return 0;
}