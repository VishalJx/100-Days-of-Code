#include <bits/stdc++.h>
using namespace std; 

class CircularQ{
    public:
        int *arr;
        int front;
        int rear;
        int size;
    
    CircularQ(int n){
        arr = new int[n];
        front = -1;
        rear = -1;
        size = n;
    }

    void enqueue(int x){
        //if queue is full
        if((rear+1)%size == front){ 
            cout << "Queue is full" << endl;
            return;
        }
        //if queue is empty
        else if(front == -1){
            front = 0;
            rear = 0;
        }
        //
        else{
            rear = (rear+1)%size; //
        }
        arr[rear] = x;
    }

    void dequeue(){
        if(front == -1){
            cout << "Queue is empty" << endl;
            return;
        }
        else if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front = (front+1)%size;
        }
    }

    int getFront(){
        if(front == -1){
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    int getRear(){
        if(rear == -1){
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty(){
        if(front == -1){
            return true;
        }
        return false;
    }

    bool isFull(){
        if((rear+1)%size == front){ //or rear == (front-1) % size
            return true;
        }
        return false;
    }
};

void print(CircularQ q){
    if(q.isEmpty()){
        cout << "Queue is empty" << endl;
        return;
    }
    int i = q.front;
    while(i != q.rear){
        cout << q.arr[i] << " ";
        i = (i+1)%q.size;
    }
    cout << q.arr[i] << endl;
} 

int main() {

    CircularQ q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    print(q);
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
    q.dequeue();

    q.enqueue(6);
    print(q);


    return 0;
}