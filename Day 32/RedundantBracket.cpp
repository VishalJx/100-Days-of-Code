//Considering expression has balanced parenthesis

#include <bits/stdc++.h>
using namespace std;

bool isRedundantBracket(string &s){
    stack <char> st;
    for(int i=0; i<s.length();i++){
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else if(ch == ')'){ // if closing bracket is encountered
            bool isRedundant = true;
            //Below while loop will check if there is any operator between opening and closing bracket
            //It is done for each set of opening and closing bracket
            while(st.top() != '('){ // pop till opening bracket is encountered
                char top = st.top();
                if(top == '+' || top == '-' || top == '*' || top == '/'){
                    isRedundant = false; // if any operator is encountered then it is not a redundant bracket
                }
                st.pop(); // pop the operator because it is not required
            }
            if(isRedundant == true){
                return true;
            }
            st.pop(); // pop the opening bracket because it is not required
        }
    }
    return false;
}
 
int main() {

    string s = "((a+b)/l)";
    if(isRedundantBracket(s)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}