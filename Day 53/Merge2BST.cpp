#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};

// Inorder traversal of BST gives sorted array
void inorder(Node* root, vector<int> &arr){
    if(root == NULL){
        return;
    }
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

//Merge two sorted array
vector<int> merge(vector<int> arr1, vector<int> arr2){
    vector<int> arr3;
    int i = 0, j = 0;
    // Merge two sorted arrays
    while(i < arr1.size() && j < arr2.size()){
        if(arr1[i] < arr2[j]){
            arr3.push_back(arr1[i]);
            i++;
        }
        else{
            arr3.push_back(arr2[j]);
            j++;
        }
    }
    while(i < arr1.size()){
        arr3.push_back(arr1[i]);
        i++;
    }
    while(j < arr2.size()){
        arr3.push_back(arr2[j]);
        j++;
    }
    return arr3;
}

//inorder to BST
Node* inorderToBST(vector<int> arr, int start, int end){
    if(start > end){
        return NULL;
    }
    int mid = (start + end)/2;
    Node* root = new Node(arr[mid]);
    root->left = inorderToBST(arr, start, mid - 1);
    root->right = inorderToBST(arr, mid + 1, end);
    return root;
}

// Merge two sorted arrays and create a new BST
Node* mergeBST(Node* root1, Node* root2){
    vector<int> arr1, arr2;
    inorder(root1, arr1);
    inorder(root2, arr2);

    vector<int> arr3;
    int i = 0, j = 0;
    // Merge two sorted arrays using above function merge
    arr3 = merge(arr1, arr2);
    // Create a new BST using above function inorderToBST
    int start = 0, end = arr3.size() - 1;
    Node* root = inorderToBST(arr3, start, end);

    return root;

}

int main(){
    Node* root1 = NULL;
    Node* root2 = NULL;

    
    
    return 0;
}

/*ALGORITHM*/
/*
    1. Convert BST into sorted array using inorder traversal
    2. Merge two sorted arrays into third new array\
    3. Convert third array into BST using inorderToBST function
*/