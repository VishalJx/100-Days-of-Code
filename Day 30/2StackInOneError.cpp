#include <bits/stdc++.h>
using namespace std;

class Stack{
    public:
        int top1, top2;
        int *arr;
        int size;

    //Constructor
    Stack(int size) {
        this -> size = size; //this keyword is used to refer to the current object
        arr = new int[size]; //dynamic memory allocation
        top1 = -1; //from bottom of stack
        top2 = size; //from top of stack 
    }

    //operations
    void push1(int x) {
        if(top2 - top1 > 1) {
            top1++;
            arr[top1] = x;
        }
        else{
            cout << "Stack Overflow" << endl;
            return;
        }

    }

    void push2(int x) {
        if(top2 - top1 > 1) {
            top2--;
            arr[top2] = x;
        }
        else{
            cout << "Stack Overflow" << endl;
            return;
        }   
    }

    int pop1(){
        if(top1>=0) {
            int x = arr[top1]; //store the top element in a variable
            top1--;
            return x; 
        }
        else{
            cout << "Stack Underflow" << endl;
            return -1;
        }
    }

    int pop2(){
        if(top2<size) {
            int x = arr[top2]; //store the top element in a variable
            top2++;
            return x; 
        }
        else{
            cout << "Stack Underflow" << endl;
            return -1;
        }
    }

    int peek1() {
        if(top1 == -1) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[top1];
    }

    int peek2() {
        if(top2 == size) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[top2];
    }

    bool isEmpty1() {
        if(top1 == -1) {
            return true;
        }
        return false;
    }

    bool isEmpty2() {
        if(top2 == size) {
            return true;
        }
        return false;
    }


};

void print1(Stack s) {
    while(!s.isEmpty1()) {
        cout << s.peek1() << " ";
        s.pop1();
    }
    cout << endl;
}

void print2(Stack s) {
    while(!s.isEmpty2()) {
        cout << s.peek2() << " ";
        s.pop2();
    }
    cout << endl;
}
 
int main() {

    Stack s(5); //creating an object of class Stack
    s.push1(10);
    s.push1(20);
    s.push1(30);
    s.push2(40);
    s.push2(50);
    print1(s);
    print2(s);
    s.pop1();
    s.pop1();
    s.pop1();
    print1(s);
    print2(s);

    return 0;
}