#include <bits/stdc++.h>
using namespace std;

int power(int base, int index){
    if(index==0)
        return 1;
    if(index==1)
        return base;
    return base*power(base, index-1);
}
 
int main() {

    int base, index;
    base = 3;
    index = 11;
    cout<<power(base, index);

    return 0;
}