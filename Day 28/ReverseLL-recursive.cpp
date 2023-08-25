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
    Node* newHead = reverseLL(head->next); //newHead is the new head of the reversed LL
    head->next->next = head; //reverse the current node
    head->next = NULL; //set the next of the current node to NULL
    return newHead; //newHead is the new head
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
    printLL(head);
    head = reverseLL(head);
    printLL(head);

    return 0;
}

/* working of abover recursion

1->2->4->NULL
newHead = reverseLL(1)
    newHead = reverseLL(2)
        newHead = reverseLL(4)
            newHead = reverseLL(NULL) //empty list
            return NULL
        4->NULL
        2->4->NULL
    4->NULL
    2->4->NULL
1->2->4->NULL
*/
