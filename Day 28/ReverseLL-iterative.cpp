#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            next = NULL;
        }
};

void insertAtTail(Node* &head, int data) {
    Node* n = new Node(data);
    if(head == NULL) {
        head = n;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

Node* reverseLL(Node* head) {
    //empty list or list with one node
    if(head == NULL || head->next == NULL) {
        return head;
    }
    Node* prev = NULL; 
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL) {
        next = curr->next; //store next node
        curr->next = prev; //reverse the current node

        prev = curr; //move prev and curr one step forward
        curr = next; //move prev and curr one step forward
    }

    return prev; //prev is the new head
}

void printLL(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout<<endl;
}
 
int main() {
    Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    printLL(head);

    //to print reverse of LL
    Node* newHead = reverseLL(head);
    printLL(newHead);
    
    return 0;
}