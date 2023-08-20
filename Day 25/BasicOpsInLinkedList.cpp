#include <bits/stdc++.h>
using namespace std;

class Node{ // class for creating a node
    public: 
    int data; // data of the node
    Node* next; // pointer to the next node

    // constructor
    Node(int data){ // constructor to initialize the data and next pointer
        this->data = data; // this is a pointer to the current object
        next = NULL; // next pointer is initialized to NULL
    }
};

// insert a node at the head
void InsertAtHead(Node* &head, int data){ // pass by reference because we do not want to copy the whole linked list
    Node* n = new Node(data); // create a new node
    n->next = head; // the next pointer of the new node points to the head
    head = n; // the head pointer now points to the new node
}

// insert a node at the tail
void InsertAtTail(Node* &tail, int data){
    Node* temp = new Node(data); // create a new node
    tail->next = temp; // the next pointer of the tail points to the new node
    tail = temp; // the tail pointer now points to the new node
}

//insert a node at a given position
void InsertAtPosition(Node* &head, int data, int pos){
    if(pos == 0){
        InsertAtHead(head, data);
    }
    else{
        Node* temp = head; // create a temporary pointer to the head
        for(int i = 0; i < pos - 1; i++){ // traverse the linked list till the previous node of the position
            temp = temp->next;
        }
        Node* n = new Node(data); // create a new node
        n->next = temp->next; // the next pointer of the new node points to the next node of the previous node
        temp->next = n; // the next pointer of the previous node points to the new node
    }
}

// delete a node at the head
void DeleteAtHead(Node* &head){
    Node* todelete = head; // create a temporary pointer to the head
    head = head->next; // the head pointer now points to the next node
    delete todelete; // delete the previous head node
}


// delete a node at a given position
void DeleteAtPosition(Node* &head, int pos){
    if(pos == 0){
        DeleteAtHead(head);
    }
    else{
        Node* temp = head; // create a temporary pointer to the head
        for(int i = 0; i < pos - 1; i++){ // traverse the linked list till the previous node of the position
            temp = temp->next;
        }
        Node* todelete = temp->next; // create a temporary pointer to the node to be deleted
        temp->next = temp->next->next; // the next pointer of the previous node points to the next node of the node to be deleted
        delete todelete; // delete the node to be deleted
    }
}

//traverse the linked list
void print(Node* &head){
    Node* temp = head; // create a temporary pointer to the head

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


 
int main() {

    Node* node1 = new Node(1); // create a new node
    Node* head = node1; // head pointer points to the first node
    Node* tail = node1; // tail pointer points to the first node
    InsertAtHead(head, 2); // insert a node at the head
    print(head); // 2 1

    InsertAtHead(head, 3); // insert a node at the head
    print(head); // 3 2 1

    InsertAtTail(tail, 4); // insert a node at the tail
    print(head); // 3 2 1 4

    InsertAtTail(tail, 5); // insert a node at the tail
    print(head); // 3 2 1 4 5

    InsertAtPosition(head, 6, 3); // insert a node at a given position
    print(head); // 3 2 1 6 4 5

    InsertAtPosition(head, 7, 0); // insert a node at a given position
    print(head); // 7 3 2 1 6 4 5

    DeleteAtPosition(head, 1); // delete a node at a given position
    print(head); // 7 2 1 6 4 5


    return 0;
}