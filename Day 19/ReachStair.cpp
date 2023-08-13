#include <bits/stdc++.h>
using namespace std;

int reachStair(int nStairs){

    if(nStairs<0) //Base Case:1
        return 0;

    if(nStairs==0) //Base Case:1
        return 1;
    
    //since we reach to current step by crossing either one(n-1) step or two(n-2) step
    return reachStair(nStairs - 1) + reachStair(nStairs - 2);

}
 
int main() {

    cout<<reachStair(4);

    return 0;
}