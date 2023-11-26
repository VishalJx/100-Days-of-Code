#include <bits/stdc++.h>
using namespace std;


//Time Complexity: O(N)
//Using KMP Algorithm
string longestPrefix(string s) {

    string ans=""; //answer will be stored in this string
    vector<int>pos(s.size(), 0); //vector to store the prefix values
    int i=0, j=1; //i is the index of the prefix and j is the index of the suffix
    while(j<s.size()){
        if(s[i]==s[j]){ //if the characters match
            pos[j]=i+1;
            i++;
            j++;
        }
        else if(i){
            i=pos[i-1];
        }
        else{
            j++;
        }
    }
    ans=s.substr(0, i);
    return ans;
}

int main(){
    string s="ababab";
    cout<<longestPrefix(s);
    
    return 0;
}