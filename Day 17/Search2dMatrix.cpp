//Matrix is sorted row-wise

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target){
    int start, end, mid, row, col;
    row = matrix.size() ;
    col = matrix[0].size(); //size of any row = no. of columns
    start = 0;
    end = col*row - 1;
    mid = start + (end-start)/2; 

    while(start<=end){
        //below is the method to find row/column number of any number who's index is known
        /*
            row = index/col;
            column = index%col;
        */
        int midPosition = matrix[mid/col][mid%col]; //the only difference between binary search on array vs matrix.
        if(midPosition == target)
            return 1;
        if(midPosition < target)
            start = mid + 1;
        else
            end = mid - 1;
        mid = start + (end-start)/2;
    }
    return 0;
}
 
int main() {

    vector<vector<int>> matrix = {{1,2,3,4},
                                  {5,6,7,8},
                                  {9,10,11,12}};

    cout<<searchMatrix(matrix, 0);

    return 0;
}