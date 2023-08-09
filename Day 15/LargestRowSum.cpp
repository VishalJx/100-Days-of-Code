#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int arr[3][3]={{1,1,1},{2,2,2},{3,3,3}};

    int max = INT_MIN; //in c++, we show small value like this
    int rowIndex = -1;
    for(int i=0;i<3;i++){
        int sum = 0;
        for(int j=0;j<3;j++){
            sum += arr[i][j];
        }
        cout<<sum<<endl; //shows row-wise sum
        if(sum>max){
            max = sum;
            rowIndex = i;
        }
    }
    cout<<"Row having largest sum: "<<rowIndex+1;

    return 0;
}