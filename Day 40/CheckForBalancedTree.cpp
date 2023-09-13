//WHAT IS BALANCED TREE
//A tree is balanced if the difference between the heights
// of its left and right subtrees is not more than one for
// all nodes of the tree.

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

//height of a tree
int height(Node* root) {

    if(root == NULL) {
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh, rh) + 1;
}

//Time Complexity: O(N^2)
bool isBalanced(Node* root) {

    if(root == NULL) {
        return true;
    }

    bool left = isBalanced(root->left); 
    bool right = isBalanced(root->right);

    bool differ = height(root->left) - height(root->right) <= 1;

    if(left && right && differ) {
        return true;
    }
    return false;

}

//Time Complexity: O(N)
pair<bool,int> isBalancedOptimised(Node* root) {

    if(root == NULL) {
        pair<bool,int> p = make_pair(true, 0);
        return p;
    }

    //left subtree
    pair <int,int> left = isBalancedOptimised(root->left);
    //right subtree
    pair <int,int> right = isBalancedOptimised(root->right);


    //check if left and right subtree are balanced
    bool leftAns = left.first;
    bool rightAns = right.first;

    //definition of balanced tree
    bool differ = abs(left.second - right.second) <= 1;

    pair<bool,int> ans;
    //comparing height of left and right subtree
    ans.second = max(left.second, right.second) + 1;

    //if left and right subtree are balanced and height of left and right subtree differ by atmost 1
    if(leftAns && rightAns && differ) {
        ans.first = true;
    }
    else {
        ans.first = false;
    }

    return ans;

}
 
int main() {

    return 0;
}