#include <bits/stdc++.h>
using namespace std;

bool bfs(int src, unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &visited){
    unordered_map<int, int> parent;

    parent[src] = -1;
    visited[src] = true;
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it: adj[node]){ //it is the neighbour of node
            if(!visited[it]){
                visited[it] = true;
                parent[it] = node;
                q.push(it);
            }
            else if(parent[node] != it){
                return true;
            }
        }
    }
}

string cycleDetection(vector<vector<int>> &edges, int n, int m){
    //adjacency list
    unordered_map<int, vector<int>> adj;
    for(auto edge: edges){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //to handle disconnected components
    unordered_map<int, bool> visited;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            if(bfs(i, adj, visited)){
                return "Yes";
            }
        }
    }

}

int main(){ 
    
    return 0;
}