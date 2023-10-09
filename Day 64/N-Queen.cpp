#include <bits/stdc++.h>
using namespace std;

void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n){
    vector<int> sol;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            sol.push_back(board[i][j]);
        }
    }
    ans.push_back(sol);
}

bool isSafe(vector<vector<int>> &board, int row, int col, int n){
    //check for upper column
    //no need to check for lower column as we are placing queens in upper columns only
    for(int i=row-1, j=col; i>=0; i--){
        if(board[i][j] == 1){
            return false;
        }
    }

    //check for upper left diagonal
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
        if(board[i][j] == 1){
            return false;
        }
    }

    //check for upper right diagonal
    for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
        if(board[i][j] == 1){
            return false;
        }
    }

    return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n){
    // base case
    if(col == n){
        addSolution(ans, board, n);
        return;
    }

    //solving one case: place in first column
    for(int row=0; row<n; row++){
        if(isSafe(board, row, col, n)){
            board[row][col] = 1;
            solve(col+1, ans, board, n); //call for next column(col+1)
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(0, ans, board, n);
    return ans;

}   

int main(){

    vector<vector<int>> ans = solveNQueens(4);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }
    
    return 0;
}