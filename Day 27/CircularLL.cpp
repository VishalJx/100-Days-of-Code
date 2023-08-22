// we do not consider head for operations in circular linked list.
// we simply use tail for all kind of operations.

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this-> data = data;
        this-> next = NULL;
    }
};

void deleteNode(Node* &tail, int element){
    if(tail == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    else{
        Node* prev = tail; //prev is pointing to the tail node
        Node* curr = prev->next; //curr is pointing to the first node
        while(curr->data != element){ //traversing till we find the element
            prev = curr; //moving prev to curr because we want to delete curr
            curr = curr->next; //moving curr to the next node
        }
        prev->next = curr->next; //making the next of prev point to the next of curr

        //if the element to be deleted is the only element, then we need to update the tail
        if(curr == prev){
            tail = NULL; 
        }

        //more than one element
        if(curr == tail){
            tail = prev; //if the element to be deleted is the last element, then we need to update the tail
        }
        curr->next = NULL;
        delete curr;
    }

}

void insertNode(Node* &tail, int data, int element){
    Node* newNode = new Node(data);
    if(tail == NULL){
        tail = newNode;
        tail->next = tail; // tail is pointing to itself
        return;
    }
    Node* temp = tail;
    while(temp->data != element){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void print(Node* tail){
    Node* temp = tail;
    if(tail == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    //do while loop is used because we want to print the last element also
    do{
        cout<<tail->data<<" "; //printing the data of the tail node
        tail = tail->next; //moving the tail pointer to the next node
    }while(temp != tail); //this condition is used to check whether we have reached the last node or not
    cout<<endl;

}

 
int main() {

    Node* tail = NULL;

    //for empty list, element can be anything
    insertNode(tail, 1, 4); //here 4 is the element after which we want to insert 1
    print(tail);

    insertNode(tail, 2, 1); //here 1 is the element after which we want to insert 2
    print(tail);

    insertNode(tail, 3, 2); 
    print(tail);

    insertNode(tail, 4, 2); 
    print(tail);

    deleteNode(tail, 6);
    print(tail);



    return 0;
}