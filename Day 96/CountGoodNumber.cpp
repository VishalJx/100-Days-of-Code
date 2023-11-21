#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int power(int x, int n){
    if(n == 0){
        return 1;
    }
    int ans = power(x, n/2);
    ans *= ans;
    ans %= mod;
    if(n%2==1){
        ans *= x;
        ans %= mod;
    }
    return ans;
}

int countGoodNumber(int n){
    int numberOfOddPlacs = n/2;
    int numberOfEvenPlaces = n/2 + n%2;
    return(power(5, numberOfOddPlacs)*power(4, numberOfEvenPlaces))%MOD
}

int main(){

    int n = 4;
    cout << countGoodNumber(n) << endl;
    
    return 0;
}