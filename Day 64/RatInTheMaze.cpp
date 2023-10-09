#include <bits/stdc++.h>
using namespace std;

bool isSafe(int newx, int newy, vector<vector<int>> &arr, int n, vector<vector<bool>> &visited){
    if ((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && arr[newx][newy] == 1 && visited[newx][newy] == false) {
        return false;
    }
    return true;

    //they must be greater than 0 and less than n
    //they must be inside the maze.
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector<bool>> &visited, string path){
    // Base Case: Destination Reached
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }

    //when start is 0
    if(arr[0][0] == 0){
        return;
    }

    //Movements : D L R U

    visited[x][y] = true; //marking visited

    //Down
    if(isSafe(x+1,y,arr,n,visited)){
        solve(x+1,y,arr,n,ans,visited,path+"D");
    }

    //Left
    if(isSafe(x,y-1,arr,n,visited)){
        solve(x,y-1,arr,n,ans,visited,path+"L");
    }

    //Right
    if(isSafe(x,y+1,arr,n,visited)){
        solve(x,y+1,arr,n,ans,visited,path+"R");
    }

    //Up    
    if(isSafe(x-1,y,arr,n,visited)){
        solve(x-1,y,arr,n,ans,visited,path+"U");
    }

    //Backtracking
    visited[x][y] = false;

}

vector<string> searchMaze(vector<vector<int>> &maze, int n){
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string path = "";

    solve(0,0,maze,n,ans,visited,path);

    return ans;
}

int main(){

    vector<vector<int>> arr = {{1,0,0,0},
                               {1,1,0,1},
                               {1,1,0,0},
                               {0,1,1,1}};
    

    vector<string> ans = searchMaze(arr,16);

    for(auto i: ans){
        cout<<i<<" ";
    }
    
    return 0;
}