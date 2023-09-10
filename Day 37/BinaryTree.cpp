//Some layman definitions:-
//Tree is a non-linear data structure which organizes data in a hierarchical structure and this is a recursive definition.
//Binary Tree: A tree whose elements have at most 2 children is called a binary tree.
//Node: The topmost element of the tree is called the root node. 
//Parent: The element directly above something is called its parent. 
//Children: The elements that are directly under an element are called its children. 
//Siblings: The elements that are at the same level are called siblings.
//Leaf: The elements that do not have any children are called leaves.

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        //Constructor
        Node(int val) {
            this -> data = val;
            this -> left = NULL;
            this -> right = NULL;
        }
};

//Building a tree:
/*
     1
   /   \
  3     5
 / \    /
7  11  17

*/
//The above tree can be represented as: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

Node* buildTree(Node* root) {
    int d;
    cout << "Enter the data: "<<endl;
    cin >> d;

    if(d == -1) {
        return NULL;
    }

    root = new Node(d);
    cout << "Enter the left child of "<<d<<endl;
    root -> left = buildTree(root -> left);
    cout << "Enter the right child of "<<d<<endl;
    root -> right = buildTree(root -> right);

    return root;
}


//Level Order Traversal : Breadth First Search
// The above linear representation of the tree is converted to a tree using below function.
// Simply pushing that linear representation into a queue and performing the below operations will give us the tree.
void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root); //pushing the root node along with all its children from buildTree() function
    q.push(NULL); //pushing NULL to mark the end of the first level
    while(!q.empty()) {
        Node* temp = q.front(); //storing the front element of the queue in a temporary node


        q.pop(); //popping the front element of the queue as it is already stored in a temporary node

        if(temp == NULL){
            cout << endl; //if the temporary node is NULL, then we have reached the end of the level
            if(!q.empty()) {
                q.push(NULL); //pushing NULL to mark the end of the next level
            }
        }
        else{
            cout << temp -> data << " "; //printing the data of the temporary node
            if(temp -> left != NULL) {
                q.push(temp -> left); //pushing the left child of the temporary node in the queue
            }
            if(temp -> right != NULL) {
                q.push(temp -> right);  //pushing the right child of the temporary node in the queue
            }
        }
    }
}


int main() {
    
    Node* root = NULL;
    root = buildTree(root);

    levelOrder(root);
    return 0;
}