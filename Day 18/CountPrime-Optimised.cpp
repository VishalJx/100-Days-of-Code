// Sieve of Eratosthenes Algorithm.

#include <bits/stdc++.h>
using namespace std;

int countPrime(int n){

    int count = 0;

    vector<int> prime(n, true);
    prime[0] = prime[1] = false;

    for(int i=2; i<n; i++){//initially we know that 2 is prime.
        if(prime[i]){      //hence it enters if-condition
            count++;

            //marking all the multiples of our test number with false(property of prime number)
            for(int j=2*i; j<n; j=j+i){
                prime[j]=0; //marking those all multiples as false(not prime)
            }
        }
    }
    return count;
}

 
int main() {

    int testNum = 23;
    cout<<testNum<<" has "<<countPrime(testNum)<<" prime numbers before it.";

    return 0;
}

/*------------Time Complexity---------------
    1. Each time we enter the loop as : n/2 + n/3 + n/5 + n/7 + ......
    2. Hence the total will be: n*log(log(n))
    3. Therefore the time complexity is : O(n*log(log(n))) -> (smaller than O(n^2))
*/