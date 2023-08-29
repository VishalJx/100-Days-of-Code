#include <bits/stdc++.h>
using namespace std;

class Stack{
    public:
        int top;
        int *arr;
        int size;

    //Constructor
    Stack(int size) {
        this -> size = size; 
        arr = new int[size]; 
        top = -1;
    }

    //operations
    void push(int x) {
        if(top == size - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++; 
        arr[top] = x; 
    }
};

//without using extra space and storing answer in the same stack
string reverse(string s){
    Stack st(s.length());
    for(int i=0 ; i<s.length() ; i++){
        st.push(s[i]); //pushing each character of the string into the stack
    }
    for(int i=0 ; i<s.length() ; i++){
        s[i] = st.arr[st.top]; //replacing each character of the string with the top element of the stack
        st.top--; //decrementing top by 1 to point to the previous element
    }
    return s;
}

int main() {
    string s = "hello";
    cout << "Reversed string: " << reverse(s) << endl;

    return 0;
}