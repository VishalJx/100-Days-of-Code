#include <bits/stdc++.h>
using namespace std;

//BFS Traversal: One node is selected and all the nodes connected to it are traversed first 
//and then the nodes connected to the nodes of the first node are traversed and so on.

void prepareAdjList(unordered_map<int, vector<int>> &adj, vector<pair<int,int>> edges){
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        //undirected graph, hence both ways
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void bfs(int src, unordered_map<int, vector<int>> &adj, vector<int> &bfs, unordered_map<int, bool> &visited){
    queue<int> q;
    q.push(src);
    visited[src] = true; //node is visited

    while(!q.empty()){
        int node = q.front(); //frontNode
        q.pop();

        //store frontNode into bfs
        bfs.push_back(node);

        //traverse all the nodes connected to the frontNode
        for(auto it: adj[node]){
            if(!visited[it]){
                q.push(it);
                visited[it] = true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int,int>> edges){
     
     //Creating Adjacency List
     unordered_map<int, vector<int>> adj;
     vector<int> bfs;
     unordered_map<int, bool> visited;

     prepareAdjList(adj, edges);

     //traverse all component of a graph
     //for loop is used because graph can be disconnected
     //otherwise for connected graph, we can simply skip this loop
     for(int i=0; i<vertex; i++){
        if(!visited[i]){
            bfs(i, adj, bfs, visited);
        }
     }

    return bfs;
}

//if needed to return answer in sorted order: use <set> instead of <vector> for adjList
// and rather than using push_back, use insert


int main(){
    
    return 0;
}