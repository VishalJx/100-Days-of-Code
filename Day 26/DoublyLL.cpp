#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int data){
        this-> data = data;
        this-> prev = NULL;
        this-> next = NULL;
    }
};

void deleteNode(Node* &head, int pos){
    if(pos == 0){ //if position is at starting i.e. head
        Node* temp = head;
        temp->next->prev = NULL; //prev of next node will point to NULL
        head = head->next; //head will now point to next node
        temp->next = NULL; //next of temp will point to NULL
        delete temp; //delete the node
    }
    else{
        Node* temp = head;
        for(int i=0; i<pos-1; i++){
            temp = temp->next;
        }
        if(temp->next->next == NULL){ //if position is at end i.e. tail
            Node* toDelete = temp->next; //node to be deleted
            temp->next = NULL; //next of temp will point to NULL
            toDelete->prev = NULL; //prev of toDelete will point to NULL
            delete toDelete; //delete the node
            return;
        }
        Node* toDelete = temp->next; //node to be deleted
        temp->next = toDelete->next; //next of temp will point to next of toDelete
        toDelete->next->prev = temp; //prev of next of toDelete will point to temp
        toDelete->next = NULL; //next of toDelete will point to NULL
        toDelete->prev = NULL; //prev of toDelete will point to NULL
        delete toDelete; //delete the node
    }
}

void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){ //empty list
    //this will be our head
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        Node* n = new Node(data);
        n->next = head; //new node point head
        head->prev = n; //now prev of head point to new node
        head = n; //new head will be new node
    }
}

void insertAtTail(Node* &tail, int data){
    if(tail == NULL){
        //this will be our tail
        Node* temp = new Node(data);
        tail = temp;
    }
    else{
        Node* n = new Node(data);
        tail->next = n; //next of tail point new node
        n->prev = tail; // prev of new node points tail
        tail = n; // new tail will be new node
    }
}

void insertAtPosition(Node* &head, Node* &tail, int data, int pos){
    //if position is at starting
    if(pos == 0){
        insertAtHead(head,tail, data);
        return;
    }
    Node* temp = head;
    for(int i=0; i < pos-1; i++){
        temp = temp->next;
    }
    //if position is at end
    if(temp->next == NULL){
        insertAtTail(tail, data);
        return;
    }
    //creating new node
    Node* n = new Node(data);
    n->next = temp->next; //new node point to next node
    temp->next->prev = n; //next node prev point to new node
    temp->next = n;
    n->prev = temp;
}

void print(Node* head){
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int getLength(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count ++;
        temp = temp->next;
    }
    return count;
}
 
int main() {

    // Node* node1 = new Node(10);
    // Node* head = node1;
    // Node* tail = node1;
    //let start from the very beginning when both head/tail are NULL;(Empty List)
    Node* head = NULL;
    Node* tail = NULL;
    print(head);

    insertAtHead(head,tail, 20);
    print(head);

    insertAtTail(tail, 30);
    print(head);

    insertAtTail(tail, 40);
    print(head);

    insertAtTail(tail, 50);
    print(head);

    insertAtTail(tail, 80);
    print(head);

    insertAtPosition(head, tail, 100, 1);
    print(head);

    deleteNode(head, 5);
    print(head);

    cout<<getLength(head);

    return 0;
}