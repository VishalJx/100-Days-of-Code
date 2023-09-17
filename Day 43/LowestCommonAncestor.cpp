#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

// Building a tree: Using Level Order Traversal
/*
        1
      /   \
     3     5
    / \    / \
   7  11  17  8
  / \
 4   9

    */

Node *buildFromLevelOrder(Node *root)
{
    queue<Node *> q;

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

// Lowest Common Ancestor: Using recursion
Node *lca(Node *root, int n1, int n2)
{
    // base case
    if (root == NULL)
        return NULL;
    
    // if root is one of the nodes
    if (root->data == n1 || root->data == n2)
        return root;
    
    // finding lca in left and right subtree
    Node *leftAns = lca(root->left, n1, n2);
    Node *rightAns = lca(root->right, n1, n2);

    // if both left and right subtree returns non-null value
    if (leftAns != NULL && rightAns != NULL)
        return root; //this will be answer
    // if one of the subtree returns non-null value
    else if (leftAns != NULL && rightAns == NULL)
        return leftAns;
    // if one of the subtree returns non-null value
    else if(leftAns == NULL && rightAns != NULL)
        return rightAns;
    // if both the subtree returns null value
    else
        return NULL;
}

int main()
{
    Node *root = NULL;
    root = buildFromLevelOrder(root);

    int n1, n2;
    cout << "Enter the two nodes: " << endl;
    cin >> n1 >> n2;

    Node *ans = lca(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is: " << ans->data << endl;

    return 0;
}