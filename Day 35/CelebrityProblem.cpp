#include <bits/stdc++.h>
using namespace std;


// Using stack : Time complexity of below is O(n)
int celebrity(vector<vector<int>> &M, int n){
    stack<int> s;
    // push all the people in the stack
    for(int i=0; i<n; i++){
        s.push(i);
    }
    // pop two people at a time and check if the first person knows the second person
    while(s.size() > 1){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if(M[a][b] == 1){
            // a knows b so a is not the celebrity
            s.push(b);
        }
        else{
            // a does not know b so b is not the celebrity
            s.push(a);
        }
    }
    // if stack is empty then there is no celebrity
    int c = s.top();
    s.pop();
    // check if the last person in the stack is the celebrity
    for(int i=0; i<n; i++){
        // if c knows someone or someone does not know c then c is not the celebrity
        if(i!=c && (M[c][i] == 1 || M[i][c] == 0)){
            return -1;
        }
    }
    return c;
}

//Time complexity of below is O(n) 
// int celebrity(vector<vector<int>> &M, int n){
//     //without using stack

//     int a = 0; // this keeps track of the celebrity
//     int b = n-1; // this keeps track of the other person
//     while(a<b){ // we will keep on checking till a<b because if a==b then we have found the celebrity
//         if(M[a][b] == 1){
//             a++; // if a knows b then a is not the celebrity
//         }
//         else{
//             b--; // if a does not know b then b is not the celebrity
//         }
//     }
//     //
//     for(int i=0; i<n; i++){
//         // if a knows someone or someone does not know a then a is not the celebrity
//         if(i!=a && (M[a][i] == 1 || M[i][a] == 0)){
//             return -1;
//         }
//     }
//     return a;

// }

 
int main() {
                                //0  1  2
    vector<vector<int>> M = /*0*/{{0, 0, 0},
                            /*1*/{0, 0, 0}, 
                            /*2*/{0, 0, 0}};
    int n = 4;
    cout << celebrity(M, n)<<" is the celebrity" << endl;

    return 0;
}