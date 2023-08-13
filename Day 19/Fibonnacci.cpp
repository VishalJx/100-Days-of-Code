#include <bits/stdc++.h>
using namespace std;

int fibonnacci(int nth){

    if(nth == 0) //Base Case:1
        return 0; 
    if(nth == 1) //Base Case:2
        return 1;

    return fibonnacci(nth - 1) + fibonnacci(nth - 2);
}
 
int main() {

    cout<<fibonnacci(3);

    return 0;
}