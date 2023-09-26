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

//inorder traversal: as this is sorted
//we'll apply two pointer approach and check if the sum exists
void inorder(Node *root, vector<int> &in){
    if (root == NULL)
        return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

bool twoSumExists(Node* root, int target){
    //two pointer approach
    vector<int> in;
    inorder(root, in);
    int i = 0, j = in.size()-1;

    while(i<j){
        if(in[i]+in[j] == target){
            cout<<in[i]<<" "<<in[j]<<endl; //just to print the pair
            return true;
        }
        else if(in[i]+in[j] < target)
            //as we need to increase the sum
            i++;
        else//as we need to decrease the sum
            j--;
    }
    return false;
}

int main(){

    Node *root = NULL;
    root = buildFromLevelOrder(root);

    cout<<twoSumExists(root, 20)<<endl;

    
    return 0;
}