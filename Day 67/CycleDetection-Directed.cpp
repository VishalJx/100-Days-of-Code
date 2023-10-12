#include <bits/stdc++.h>
using namespace std;


bool dfs(int node, unordered_map<int , vector<int>> &adj, unordered_map<int , bool> &visited, unordered_map<int , bool> &dfsVisited){
    visited[node] = true;
    dfsVisited[node] = true;

    for(auto it : adj[node]){
        //if the node is not visited then call dfs on it
        if(!visited[it]){
            if(dfs(it, adj, visited, dfsVisited)){
                return true;
            }
        }
        //if the node is visited and it is in the dfsVisited then it is a cycle
        else if(dfsVisited[it]){
            return true;
        }
    }
    dfsVisited[node] = false; //backtracking
    return false;
}

//using DFS
int detectCycle(int n, vector<pair<int , int>> &edges){
    //adjacency list
    unordered_map<int , vector<int>> adj;
    for(int i=;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        //only for directed graph
        adj[u].push_back(v);
    }

    //call dfs
    unordered_map<int , bool> visited;
    unordered_map<int , bool> dfsVisited;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            if(dfs(i, adj, visited, dfsVisited)){
                return true;
            }
        }
    }
}


int main(){
    
    return 0;
}