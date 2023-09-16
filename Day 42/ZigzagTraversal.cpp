include<bits / stdc++.h> using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    };
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
    queue<Node *> q;

    // for root node
    int data;
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

vector<int> zigZag(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    queue<Node *> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp;
        while (size--)
        {
            Node *node = q.front();
            q.pop();

            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }

            if (leftToRight)
            {
                temp.push_back(node->data);
            }
            else
            {
                temp.insert(temp.begin(), node->data);
            }
        }
        leftToRight = !leftToRight;
        for (auto it : temp)
        { // for(int i=0; i<temp.size(); i++)
            ans.push_back(it);
        }
    }
    return ans;
}

int main()
{

    Node *root = NULL;
    root = buildFromLevelOrder(root);

    vector<int> ans = zigZag(root);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}