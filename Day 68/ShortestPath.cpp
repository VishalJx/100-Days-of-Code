//In Undirected Graph

#include <bits/stdc++.h>
using namespace std;

//using BFS
vector<int> shortestPath(vector<pair<int, int> > edges, int n, int m, int s, int t){
    //adjacency list
    unordered_map<int, vector<int> > adj;
    for(int i=0; i<m; i++){
        int u = edges[i].first;
        int v = edges[i].second;

        //undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //do bfs
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(s);
    parent[s] = -1;
    visited[s] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(auto neighbour: adj[curr]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
                parent[neighbour] = curr;
            }
        }
    }
    //prepare the shortest path
    vector<int> path;
    int curr = t;
    ans.push_back(curr);

    while(curr != -1){
        curr = parent[curr];
        path.push_back(curr);
    }
    reverse(path.begin(), path.end());
    
    return path;

}


int main(){
    
    return 0;
}