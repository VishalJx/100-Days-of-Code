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

//Creates mapping
//returns the target node
Node* createParentMapping(Node* root, int target, map<Node*, Node*> &nodeToParent){
    Node* result = NULL;
    queue<Node*> q;
    q.push(root);

    nodeToParent[root] = NULL;  //Root has no parent

    //Breath First Search
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        //If the target node is found

        //Store the target node in result
        if(front->data == target){
            result = front;
        }
        //If the left child exists
        if(front->left){
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        //If the right child exists
        if(front->right){
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return result;
}

//Burning the tree
int burnTree(Node *root, map<Node*, Node*>, Node *target){
    map<Node*, bool> visited;
    queue<Node*> q;

    q.push(root);
    visited[root] = true;

    int ans = 0;

    while(!q.empty()){

        bool flag = false;
        int size = q.size();
        for(int i=0; i<size; i++){
            //produce neighbouring nodes
            Node *front = q.front();
            q.pop();
            //visiting front ka left
            if(front->left && !visited[front->left]){
                flag = true;
                q.push(front->left);
                visited[front->left] = true;
            }
            //visiting front ka right
            if(front->right && !visited[front->right]){
                flag = true;
                q.push(front->right);
                visited[front->right] = true;
            }
            //visiting front ka parent
            if(nodeToParent[front] && !visited[nodeToParent[front]]){
                flag = true;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
        }
        if(flag){
            ans++;
        }
    }
    return ans;
}

int minTime(Node *root, int target){
    map<Node*, Node*> nodeToParent;

    Node *targetNode = createParentMapping(root, target, nodeToParent);
    int ans = burnTree(root, nodeToParent, targetNode);
    return ans;
}

int main(){
    
    return 0;
}

/*---------------Alorithm-------------*/
/*
    1.Create a map to store the parent of each node.
    2.Find the target node and store it in a queue.
    3.Traverse the queue and find the parent of each node and store it in a queue.
    4.Keep track of the time.
    5.Return the time.
*/