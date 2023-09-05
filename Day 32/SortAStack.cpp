//Without using any loop, sort the elements of the stack in ascending order using recursion.

#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int temp) {
    if (s.empty() || s.top() <= temp) { // if stack is empty or top element is smaller than temp
        s.push(temp);  // then push temp 
        return;
    }
    int val = s.top(); // else store top element in val
    s.pop(); // pop the top element
    // recursive call
    insert(s, temp); // call insert for remaining stack
    s.push(val); // push val back to stack
}

void sortStack(stack<int> &s) {
    if (s.empty()) // base case
        return;

    int temp = s.top();
    s.pop();
    // recursive call
    sortStack(s);
    insert(s, temp);
}
 
int main() {

    stack<int> s;
    s.push(30);
    s.push(-5);
    s.push(18);
    s.push(14);
    s.push(-3);
    cout << "Stack elements before sorting: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    s.push(30);
    s.push(-5);
    s.push(18);
    s.push(14);
    s.push(-3);
    sortStack(s);
    cout << "Stack elements after sorting: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}