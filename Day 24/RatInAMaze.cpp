#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>> &visited,vector<vector<int>> &maze){
    //we'll be checking three conditions here
    //1. Whether the rat is moving outside the maze
    //2. Visited is zero or not
    //3. path must be open(maze[x][y]==1)
    if((x>=0 && x<n)&&(y>=0 && y<n) && visited[x][y]==0 && maze[x][y]==1){
        return true;
    }
    else
        return false;
}

void solve(vector<vector<int>> &maze, int n, vector<string> &ans, int x, int y,vector<vector<int>> &visited, string path){
    //we have reached x,y here

    //base case: rat reached at the end
    if(x==n-1 && y==n-1){
        ans.push_back(path); //we push the path character(D,U,L,R) in our answer
    }

    visited[x][y] = 1;

    //Down
    int newx = x+1;
    int newy = y;
    if(isSafe(newx,newy,n,visited,maze)){ //checking conditions
        path.push_back('D');
        solve(maze,n,ans,newx,newy,visited,path);
        path.pop_back();
    }

    //Up
    newx = x-1;
    newy = y;
    if(isSafe(newx,newy,n,visited,maze)){
        path.push_back('U');
        solve(maze,n,ans,newx,newy,visited,path);
        path.pop_back();
    }

    //Left
    newx = x;
    newy = y-1;
    if(isSafe(newx,newy,n,visited,maze)){
        path.push_back('L');
        solve(maze,n,ans,newx,newy,visited,path);
        path.pop_back();
    }

    //Right
    newx = x;
    newy = y+1;
    if(isSafe(newx,newy,n,visited,maze)){
        path.push_back('R');
        solve(maze,n,ans,newx,newy,visited,path);
        path.pop_back();
    }

    visited[x][y] = 0;

}

vector<string> findPath(vector<vector<int>> &maze, int n){

    vector<string> ans; // final answer will be stored here. 

    if(maze[0][0] == 0){ //when the starting block is zero itself
        return ans; 
    }

    //initialising source position of our rat
    int srcx = 0;
    int srcy = 0;

    // to keep track of visited cells, so that our rat does not get stuck in any infinite loop.
    vector<vector<int>> visited = maze;
    //initialise all cell with zero representing not visited.
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = 0;
        }
    }

    //this will be the string denoting the moves -> D,U,L,R
    string path="";
    solve(maze,n,ans,srcx,srcy,visited,path); //recursive function
    sort(ans.begin(), ans.end()); //to sort answer in lexical order
    return ans;
} 

int main() {

    vector<vector<int>> maze = {{1, 0, 0, 0},
                               {1, 1, 0, 1}, 
                               {1, 1, 0, 0},
                               {0, 1, 1, 1}};
    int n = maze.size();

    //simply printing vector answer
    vector<string> sol = findPath(maze,n);
    for(int i=0;i<sol.size();i++){
        cout<<sol[i]<<endl;
    }
    return 0;
}