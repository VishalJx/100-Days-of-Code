#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

void insertAtTail(Node* &head, int data){
    Node* n = new Node(data);
    if(head == NULL){
        head = n;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* reverseInK(Node* &head, int k){
    if(head == NULL){
        return NULL;
    }
    //reverse first k nodes
    Node* next = NULL; //stores the next node
    Node* curr = head; //stores the current node
    Node* prev = NULL; //stores the previous node
    int count = 0; //stores the number of nodes reversed

    while(curr != NULL && count < k){
        next = curr->next; //store next node
        curr->next = prev; //reverse the current node

        prev = curr; //move prev and curr one step forward
        curr = next; //move prev and curr one step forward
        count++;
    }

    //next is now a pointer to (k+1)th node
    //recursively call for the list starting from curr
    //and make rest of the list as next of first node
    if(next != NULL){
        head->next = reverseInK(next, k);
    }

    //prev is new head of the input list
    return prev;

}

 
int main() {

    Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    insertAtTail(head, 9);
    insertAtTail(head, 10);
    print(head);
    Node* newHead = reverseInK(head, 2);
    print(newHead);

    return 0;
}