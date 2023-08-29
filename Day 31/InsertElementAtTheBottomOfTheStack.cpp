#include <bits/stdc++.h>
using namespace std;

class Stack{
    public:
        int top;
        char *arr; //changed from int to char
        int size;

    //Constructor
    Stack(int size){
        this -> size = size; 
        arr = new char[size]; 
        top = -1;
    }

    //operations
    void push(char x){
        if(top == size -1){ 
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop(){
        if(top == -1){
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }

    char peek(){
        if(top == -1){
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top];
    }
};

void insertAtBottom(Stack &s, char x){
    if(s.top == -1){
        s.push(x);
        return;
    }

    char data = s.peek(); //store the top element of stack
    s.pop(); //pop the top element of stack
    insertAtBottom(s, x); //recursively call the function
    s.push(data); //push back the top element of stack
}

void print(Stack s){
    while(s.top != -1){
        cout << s.peek() << " ";
        s.pop();
    }
    cout << endl;
}
 
int main() {

    Stack s(10);
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    print(s);
    insertAtBottom(s, 'e');
    print(s);

    return 0;
}