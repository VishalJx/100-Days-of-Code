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

};

bool isValid(string para){

    Stack s(10);

    //--> If opening bracket then -> push to stack
    //--> If closing bracket then -> check if top of stack is opening bracket of same type

    for(int i = 0; i < para.length(); i++){
        if(para[i] == '(' || para[i] == '{' || para[i] == '['){ //if opening bracket, push to stack
            s.push(para[i]);
        }
        else if(para[i] == ')' || para[i] == '}' || para[i] == ']'){
            if(s.top == -1){ //if stack is empty, then it is invalid
                return false;
            }
            else if(para[i] == ')' && s.arr[s.top] == '('){ //matching the top element of stack with the current element
                s.pop();
            }
            else if(para[i] == '}' && s.arr[s.top] == '{'){
                s.pop();
            }
            else if(para[i] == ']' && s.arr[s.top] == '['){
                s.pop();
            }
            else{
                return false;
            }
        }
    }
    //After all processing, if stack is empty, then it is valid
    if(s.top == -1){
        return true;
    }
    else{
        return false;
    }

}

 
int main() {
    string s = "({[]})";
    if(isValid(s)){
        cout << "Valid" << endl;
    }
    else{
        cout << "Invalid" << endl;
    }
    return 0;
}