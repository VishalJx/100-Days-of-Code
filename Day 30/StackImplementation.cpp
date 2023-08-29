#include <bits/stdc++.h>
using namespace std;
//STACK IMPLEMENTATION USING ARRAY//

class Stack {
    public:
        int top;
        int *arr;
        int size;

    //Constructor
    Stack(int size) {
        this -> size = size; //this keyword is used to refer to the current object
        arr = new int[size]; //dynamic memory allocation
        top = -1;
    }

    //operations
    void push(int x) {
        if(top == size - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++; //increment top by 1 to point to the next empty space
        arr[top] = x; //insert the element at the top
    }

    void pop(){
        if(top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--; //decrement top by 1 to point to the previous element
    }

    int peek() {
        if(top == -1) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        if(top == -1) {
            return true;
        }
        return false;
    }

};

void print(Stack s) {
    while(!s.isEmpty()) {
        cout << s.peek() << " ";
        s.pop();
    }
    cout << endl;
}
 
int main() {

    Stack s(5); //creating an object of class Stack
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    print(s);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout << s.peek() << endl;
    cout << s.isEmpty() << endl;

    return 0;
}