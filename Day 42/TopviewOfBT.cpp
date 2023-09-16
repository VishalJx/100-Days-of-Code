#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;

    Node(int val)
    {
        data = val;
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

// Top View of Binary Tree
vector <int> topView(Node *root){
    vector <int> ans;
    if(root == NULL) return ans;

    // line, node
    map <int, int> topNode;
    //to store the line number of the node
    queue <pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair <Node *, int> temp = q.front();

        Node *frontNode = temp.first; // node
        int hd = temp.second; // horizontal distance

        if(topNode.find(hd) == topNode.end()){
            topNode[hd] = frontNode->data;
        }
        if(frontNode->left){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
    for(auto i: topNode){
        ans.push_back(i.second);
    }
    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildFromLevelOrder(root);

    vector <int> ans = topView(root);
    for(auto i: ans){
        cout << i << " ";
    }

    return 0;
}