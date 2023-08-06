#include <bits/stdc++.h>
using namespace std;

//check whether all characters are alphanumeric or not;
char isValid(char c){
    if((c>='a'&&c<='z') ||(c>='0'&&c<='9') ||(c>='A'&&c<='B')){
        return true;
    }
    else
        return false;
}

//convert all to lower case
char toLower(char c){
    if((c>='a'&&c<='z') ||(c>='0'&&c<='9')){
        return c;
    }
    else{
        char temp = c - 'A' + 'a';
        return temp;
    }
}

bool isPalindrome(string a){
    int start=0;
    int end = a.length();
    while(start<=end){
        if(a[start++] != a[end--]){
            return false;
        }
        else{
            start ++;
            end --;
        }
    }
        return true;
}

//for final, we'll remove characters otherthan alphanumerics and then
//check for palindrome
bool checkPalindrome(string s){
    string temp;

    for(int j=0;j<s.length();j++){
        //if not alphanumeric then will not go inside temp array.
        if(isValid(j)){
            temp.push_back(j); //stl to push elements in string
        }

        //to lower-case
        for(int i=0; i<s.length();i++){
            temp[i] = toLower(temp[i]);
        }

        //check for palindrome(returns true or false);
        return isPalindrome(temp);
    }

}
 
int main() {

    string s = "Wow wow";

    cout<<checkPalindrome(s);

    return 0;
}