#include <bits/stdc++.h>
using namespace std;

string reverseString(string &s, int size, int start, int end){ //Note: we pass string by reference

    if(size==1)
        return s;
    
    swap(s[start++], s[end--]);

    return reverseString(s, size-2, start, end);
    
}
 
int main() {
    string s = "abcde";
    int size = s.length();
    int start = 0;
    int end = size-1;

    cout<<reverseString(s,size, start, end);

    return 0;
}