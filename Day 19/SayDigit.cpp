#include <bits/stdc++.h>
using namespace std;

void sayDigit(int num){

    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    if(num==0) //Base Case
        return;

    int digit = num % 10; //getting the last digit
    num = num / 10; //removing the last digit

    sayDigit(num);
    cout<<arr[digit]<<" ";


}
 
int main() {

    sayDigit(100);

    return 0;
}