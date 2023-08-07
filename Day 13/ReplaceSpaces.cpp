#include <bits/stdc++.h>
using namespace std;

string replaceSpaces(string &s){

    string temp =""; //temporary string so that we can put multiple values in place of space.
    int start = 0;
    int n = s.length();
    while(start < n){
        if(s[start] ==' '){//if space found
            // s[start] = '@'; //put here whatever you want to space be replaced with.
            //What if we need to put "@40"? it won't be pushed like above. We need different method.
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else{
            temp.push_back(s[start]);//if not space then simply push the i-th character of string s.
        }
        start++;
    }
    return temp;
}
 
int main() {

    string s = "coding ninjas is a coding platform hello";
    cout<<replaceSpaces(s);

    return 0;
}