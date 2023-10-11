#include <bits/stdc++.h>
using namespace std;


void dfs(int src, unordered_map<int, vector<int>> &adj, vector<int> &component, unordered_map<int, bool> &visited){
    visited[src] = true;
    component.push_back(src);

    for(auto it: adj[src]){
        if(!visited[it]){
            dfs(it, adj, component, visited);
        }
    }
}


vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges){
    
    //preparing adjacency list
    unordered_map<int, vector<int> > adj;
    for(int i=0; i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        //undirected graph, hence both ways
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    //traverse all component of a graph if nodes are not visited
    for(int i=0; i<V; i++){
        if(!visited[i]){
            vector<int> temp;
            dfs(i, adj, temp, visited);
            ans.push_back(temp);
        }
    }

    return ans;

}

int main(){
    
    return 0;
}