#include <bits/stdc++.h>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRow, int mCol){

    vector<int> temp;//temporary vector to store the 2d array in linear fashion
    for(int col=0; col<mCol; col++){
        if(col%2 == 0){
            //for even column number
            for(int row=0; row<nRow; row++){
                cout<<arr[row][col]<<" "<<row<<col<<endl;
                temp.push_back(arr[row][col]);
            }
        }
        else{//for odd column number
            int row = nRow-1;
            while(row>=0){
                cout<<arr[row][col]<<" "<<row<<col<<endl;
                temp.push_back(arr[row][col]);
                row--;
            }
        }
    }

    return temp;
}

 
int main() {

    vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
    wavePrint(arr,3,3);
    return 0;
}