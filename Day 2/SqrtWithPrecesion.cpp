// Question:- Find square root of a number using binary search.
// Question Link:- https://www.codingninjas.com/codestudio/problems/square-root_893351?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2

#include <bits/stdc++.h>
using namespace std;

int squareRootTemp(int number){
    int start = 0;
    int end = number;
     int mid = start + (end - start)/2;

     int ans = -1;
     while(start <= end){
        if(mid*mid == number){
            return mid;
        }
        else if(mid*mid > number){
            end = mid-1;
        }
        else if(mid*mid < number){
            ans = mid; //since all number less than mid can be solution, hence storing it.
            start = mid + 1;
        }
        mid = start + (end - start)/2;
     }
     return ans;
}

//to calculate more precision
double morePrecision(int number, int precision, int tempSolution ){
    double factor = 1;
    double ans = tempSolution; //this is our integer part of the square root which will be added with factor.

    for (int j = 0; j<precision; j++){
        factor = factor/10;
        //0.1, 0.01, 0.001
        for(double i = ans; i*i < number; i = i + factor){
            /*
            1. Precision is only for non-perfect numbers
            2. If we have a perfect number, then we will not enter this loop.
            3. If precision is 3, then we will check for 0.1, 0.01, 0.001 and keep adding "i" with factor.
            4. Ex. At first ans = i = 5; 
            5. Now, i*i = 25 < 34, hence we will enter the loop 
               assign value of "i" back to "ans" and add 0.1 to i.
               New value of i = ans = 5.1 hence check 5.1*5.1 < 34;
               if not then add factor i.e. 0.1 to new "i" = 5.1; will become i = 5.2.
               Process continues till we get precision of 0.1 decimal
            6. Once we get precision of 0.1 decimal, we will move to next decimal i.e. 0.01
            7. We will again check for 5.01, 5.02, 5.03 and so on, it continues
            */
            ans = i;
        }
    }
    return ans;
}

int main() {

    int number = 34;
    int tempSol  = squareRootTemp(number);

    cout<<morePrecision(number, 3, tempSol)<<endl;

    return 0;
}