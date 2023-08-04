#include <bits/stdc++.h>
using namespace std;

int getLength(char string[]){
    int count = 0;
    for(int i=0; string[i]!='\0';i++){
        count++;
    }
    return count;
}

void reversedString(char string[], int length){
    int start=0;
    int end = length - 1;

    while(start<end){
        swap(string[start], string[end]);
        start++;
        end--;
    }
}

int main() {
    char string[20];
    cout<<"Enter The String: "<<endl;
    cin>>string;

    int length = getLength(string);

    reversedString(string, length);
    cout<<"Reversed String is: "<<string<<endl;

    return 0;
}