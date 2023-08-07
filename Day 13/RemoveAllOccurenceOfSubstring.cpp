/*Problem is solved completely using STL functions - find() and remove();*/
// Do read note.md;

#include <bits/stdc++.h>
using namespace std;

string removeOccurence(string &s, string part){
    while(s.length()!=0 && s.find(part)<s.length()){
        s.erase(s.find(part), part.length());
    }
    return s;
}
 
int main() {

    string s = "aabbccaabbhhababbaab";
    string part = "aabb";
    cout<< removeOccurence(s, part);

    return 0;
}

