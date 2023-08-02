#include <bits/stdc++.h>
using namespace std;

void rotateArray(vector<int>arr, int k){
    //creating temporary array to store values
    //we need temp array, other if we try to solve only with arr,then it may get overwritten.
    vector<int> temp(arr.size()); //size of temp array will be same as size of parent array.

    for(int i=0; i<arr.size(); i++){
        temp[(i+k)%arr.size()] = arr[i];
    }

    //copying all values of "temp" back to 'arr'
    arr = temp;

    //printing array
    for(int p=0;p<arr.size();p++){
        cout<<arr[p];
    }
}
 
int main() {
    vector<int> arr={1,2,3,4,5};
    int k = 2;

    rotateArray(arr,k);

    return 0;
}

/*Modulo Operator(%).
    1. Whenever (num1%num2), the answer always is
        in the range of (0 to num2).
    2. (i+k)%size will give answer within (0,size);
    3. Hence when we need to shift last element ahead by two positions
        i.e. n--n+1--n+2; therefore to reverse the array in cyclic manner we use 
        module, so that the positions must not exceed "n"(size of array).
    2. Not used here but keep in mind:-
        Also whenever (num1%10), gives unit place of num1,
            whenever (num1%100), gives tens place of num1,
            .
            .
            .
            goes on
*/