#include <bits/stdc++.h>
using namespace std;

int SquareRoot(int num){

    int start, end, mid;
    start = 0;
    end = num;

    mid = start + (end - start)/2;

    int answer = -1;
    while(start <= end){

        int square = mid*mid;
        
        if(square == num)
            return mid;

        if(square > num)
            end = mid - 1;

        if(square < num){
            answer = mid;  //since all number less than mid can be solution, hence storing it.
            start = mid + 1;
        }

        mid = start + (end - start)/2;
    }

    return answer;

}


int main() {
    int num = 0;
    cout<<"Enter an Integer: ";
    cin >> num;

    cout <<"The square root of "<<num<<" is "<< SquareRoot(num);

    return 0;
}