#include <bits/stdc++.h>
using namespace std;

vector<int> spiralPrint(vector<vector<int>> arr){

    vector<int> temp;
    int row = arr.size();
    int col = arr[0].size();

    int count = 0;
    int total = row*col; //total number of present elements

    int startRow = 0;
    int startCol = 0;
    int endRow = row - 1;
    int endCol = col - 1;

    while(count<total){
        //printing starting row
        for(int index=startCol;count<total && index<=endCol; index++){
            temp.push_back(arr[startRow][index]);
            count++;
        }
        startRow++;

        //printing ending column
        for(int index=startRow;count<total && index<=endRow; index++){
            temp.push_back(arr[index][endCol]);
            count++;
        }
        endCol--;

         //printing ending row
        for(int index=endCol;count<total && index>=startCol; index++){
            temp.push_back(arr[endRow][index]);
            count++;
        }
        endRow--;

        //printing starting column
        for(int index=endRow;count<total && index>=startRow; index++){
            temp.push_back(arr[index][startCol]);
            count++;
        }
        startCol++;
    }
    return temp;
}
 
int main() {
    vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
    spiralPrint(arr);
    return 0;
}