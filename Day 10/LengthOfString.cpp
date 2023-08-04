#include <bits/stdc++.h>
using namespace std;

int getLength(char string[]){
    int count = 0;
    /* We know that any character array in c/c++ terminates with a null character '\0'
        Hence we'll iterate the character array until we find null character
    */
    for(int i=0; string[i]!='\0';i++){
        count++;
    }

    return count;
}
 
int main() {
    char name[10];

    cout<<"Enter Your Name: "<<endl;
    cin>>name; //Keep in mind that cin only takes continuous string,
               // if space/tab/break-line is used then it will terminate the input process.
               
    cout<<"Your name is: "<<name<<endl;
    cout<<"Length is: "<<getLength(name)<<endl;

    return 0;
}