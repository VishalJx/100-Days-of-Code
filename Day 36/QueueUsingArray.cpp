#include <bits/stdc++.h>
using namespace std;

class Queue {
    public:
        int *arr;
        int front;
        int rear;
        int size;
    
    // Constructor
    Queue(int n) {
        arr = new int[n];
        front = -1;
        rear = -1;
        size = n;
    }

    // Enqueue
    void enqueue(int x) {
        if (rear == size - 1) {
            cout << "Queue is full" << endl;
            return;
        }
        rear++;
        arr[rear] = x; //pushing from rear
        if (front == -1) {
            front++;
        }
    }

    // Dequeue
    void dequeue() {
        //when queue is empty we reset front and rear to -1
        if(front == rear){
            front = -1;
            rear = -1;
            return;
        }
        else if (front == -1 || front > rear) {
            cout << "No elements in queue" << endl;
            return;
        }
        front++; //popping from front
    }

    // Front
    int getFront() {
        if (front == -1 || front > rear) { //front == rear
            cout << "No elements in queue" << endl;
            return -1;
        }
        return arr[front];
    }

    // Rear
    int getRear() {
        if (front == -1 || front > rear) {
            cout << "No elements in queue" << endl;
            return -1;
        }
        return arr[rear];
    }

    // isEmpty
    bool isEmpty() {
        if (front == -1 || front > rear) {
            return true;
        }
        return false;
    }
};

//printing the queue
void print(Queue q) {
    while (!q.isEmpty()) {
        cout << q.getFront() << " ";
        q.dequeue();
    }
    cout << endl;
}
 
int main() {

    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    print(q);
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
    q.dequeue();
    print(q);

    return 0;
}