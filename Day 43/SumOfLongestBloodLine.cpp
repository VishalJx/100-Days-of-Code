#include <bits/stdc++.h>
using namespace std;

class Node{

    public:
        int data;
        Node *left, *right;

        Node(int data){
            this->data = data;
            left = right = NULL;
        }
};

// Building a tree: Using Level Order Traversal
/*
     1
   /   \
  3     5
 / \    /
7  11  17

*/
Node *buildFromLevelOrder(Node *root)
{
    queue<Node*> q;

    // for root node
    int data;
    cout << "Enter the root node: " << endl;
    cin >> data;
    root = new Node(data);
    q.push(root);

    // for other nodes
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter the left child of " << temp->data << endl;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout << "Enter the right child of " << temp->data << endl;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }

    }
    
    return root;
}

//first we need to check maximum length of path and then maximum sum of path
void solve(Node *root, int len, int &maxLen, int sum, int &maxSum){
    // base case
    if(root == NULL){ // if path ends
        if(len > maxLen){ // if length is greater than maxLen
            maxLen = len;
            maxSum = sum;
        }
        // if length is equal to maxLen
        else if(len == maxLen && sum > maxSum){
            maxSum = sum;
        }
        return;
    }
    sum = sum + root->data;

    solve(root->left, len+1, maxLen, sum, maxSum);
    solve(root->right, len+1, maxLen, sum, maxSum);
}

int sumOfLongestBloodLine(Node *root){
    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum = 0;

    solve(root, len, maxLen, sum, maxSum);

    return maxSum;
}

int main(){

    Node *root = NULL;

    root = buildFromLevelOrder(root);

    cout << sumOfLongestBloodLine(root) << endl;

    return 0;
}