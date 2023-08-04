#include <bits/stdc++.h>
using namespace std;

int getLength(char string[]){
    int count = 0;
    for(int i=0; string[i]!='\0';i++){
        count++;
    }
    return count;
}

//considering upper-case character not same as lower-case characters
bool isPalindrome(char string[], int length){
    int start=0;
    int end = length - 1;

    while(start<end){
        if(string[start++]!=string[end--])
            return 0;
        else 
            return 1;
    }
}

int main() {
    char string[20];
    cout<<"Enter The String: "<<endl;
    cin>>string;

    int length = getLength(string);

    bool value = isPalindrome(string, length);
    
    if(value){
        cout<<"Palindrome"<<endl;
    }
    else{
        cout<<"Not Palindrome"<<endl;
    }

    return 0;
}