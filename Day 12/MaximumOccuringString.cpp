#include <bits/stdc++.h>
using namespace std;

char getMaxOccur(string s){
    //will be storing the counts corresponding alphabets from a-z & A-Z inside this array.
    int arr[26] = {0}; //Initialising empty array

    //Creating array of count of alphabets
    for(int i=0; i<s.length();i++){
        char ch = s[i]; //temporary 
        //for lower a-z
        int number = 0;
        if(ch>='a' && ch<='z'){
            number = ch - 'a'; //finding the position ex. if ch='d', then 'd'-'a'= 4
        }
        //for uppercase 'A'-'Z'
        else{
            number = ch - 'A';
        }
        //adding the count in array
        arr[number]++;
    }

    //finding maximum occurence
    int maxi = -1; //initial max value
    int ans = 0;
    for(int i=0; i<26;i++){
        if(maxi < arr[i]){
            ans = i; //index of current max value
            maxi = arr[i]; //value of current max
            /*I'm saying current max because each element is compared
            one by one and each time a new max value is stored in answer until
            the final max */
        }
    }
    //our answer
    char finalAns = 'a' + ans;
    return finalAns;
}
 
int main() {

    string s = "Ommit";
    cout<<getMaxOccur(s);
}
