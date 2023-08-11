//Matrix is sorted in both row and column

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target){

    int row = matrix.size();
    int col = matrix[0].size();

    int rowIndex = 0;
    int colIndex = col - 1;

    while(rowIndex < row && colIndex >= 0){
        //targeting very first element of last column and try to appply binary search
        int element = matrix[rowIndex][colIndex]; //in our case its 4

        if(element == target){
            return 1;
        }
        //if its larger than our expected element then chcek next row
        if(element < target){
            rowIndex ++;
        }
        //if its smaller than our expected element then chcek next previous column
        else{
            colIndex--;
        }
    }
    return 0;
}
 
int main() {
    vector<vector<int>> matrix = {{1,2,3,4},
                                  {8,12,15,20},
                                  {10,14,18,32}};

    cout<<searchMatrix(matrix, 14);
    return 0;
}