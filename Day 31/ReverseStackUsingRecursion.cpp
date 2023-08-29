//First solve the insertAtBottom problem using recursion

#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s, int x) {
    if (s.empty()) {
        s.push(x);
        return;
    }
    int y = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(y);
}   

void reverseStack(stack<int> &s) {
    if (s.empty()) {
        return;
    }
    int x = s.top(); //store the top element
    s.pop(); //remove the top element
    reverseStack(s); //reverse the remaining stack
    insertAtBottom(s, x); //insert the top element at the bottom of the stack
}

void print(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
 
int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    print(s);
    reverseStack(s);
    print(s);
    return 0;
}