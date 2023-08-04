#include <bits/stdc++.h>
using namespace std;

// function must be 'char' type because for 'int' type it returns ASCII value;
char toLower(char ch){
    //below 'if' check for character between 'a'---to---'z';
    if(ch>='a' && ch<='z')
        return ch;
    else{
        /*To Understand below
        1. let 'ch' be 'B'.
        2. if we 'B' - 'A', then it gives 1, cause both are 1 character away(check boths ASCII value).
        3. after that we add 'a', i.e. 1 + 'a', i.e. 1 character ahead of 'a' 
            that must be 'b'. This will be our answer.        
        */
        char temp = ch - 'A' + 'a';
        return temp;
    }
}
 
int main() {

    cout<<"Lower case will be: "<<toLower('B')<<endl;

    return 0;
}