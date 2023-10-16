#include <bits/stdc++.h>
using namespace std;

//Spanning Tree: A tree that connects all the vertices of a graph with minimum possible number of edges
//Hence, a spanning tree does not have cycles and it cannot be disconnected
//Spanning tree has n-1 edges, where n is the number of nodes (vertices).

//Minimum Spanning Tree: A spanning tree with weight less than or equal to the weight of every other spanning tree is called a minimum spanning tree.

//Prim's Algorithm: It is a Greedy Algorithm
vector<pair<pair<int,int>, int>> primsMST(int n, int m, vector<pair<pair<int,int>, int>> edges){
    //adjacency list
    unordered_map<int, vector<pair<int, int>>> adj;
    for(int i=0; i<m; i++){
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        int w = edges[i].second;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n+1);
    vector<int> parent(n+1);
    vector<bool> mst(n+1);

    for(int i=0; i<=n; i++){
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    key[1] = 0;
    parent[1] = -1;

    for(int i=0; i<n-1; i++){
        int mini = INT_MAX;
        int u;
        //find the minimum key value node from the set of nodes not yet included in MST
        for(int j=1; j<=n; j++){
            if(mst[j]==false && key[j]<mini){
                mini = key[j];
                u = j;
            }
        }
        //add the minimum key value node to the MST
        mst[u] = true;
        //update the key values of the adjacent nodes of the picked node
        for(auto neighbour: adj[u]){
            int v = neighbour.first;
            int weight = neighbour.second;
            if(mst[v]==false && weight<key[v]){
                parent[v] = u;
                key[v] = weight;
            }
        }
    }

    vector<pair<pair<int,int>, int>> mstEdges;
    for(int i=2; i<=n; i++){
        mstEdges.push_back(make_pair(make_pair(parent[i], i), key[i]));
    }

    return mstEdges;

}

int main(){
    
    return 0;
}