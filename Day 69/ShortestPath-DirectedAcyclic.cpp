#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int w){
        adj[u].push_back({v, w});
    }

    void printAdj(){
        for(auto i: adj){
            cout<<i.first<<"->";
            for(auto j: i.second){
                cout<<"("<<j.first<<","<<j.second<<")";
            }
            cout<<endl;
        }
    }

    void dfs(int src, unordered_map<int, int> &visited, stack<int> &s){
        visited[src] = true;
        for(auto i: adj[src]){
            if(!visited[i.first]){
                dfs(i.first, visited, s);
            }
        }
        s.push(src);
    }

    void getShortestPath(int src, vector<int> &dist, stack<int> &s){
        dist[src] = 0;
        while(!s.empty()){
            int node = s.top();
            s.pop();

            if(dist[node]!=INT_MAX){
                for(auto i: adj[node]){
                    if(dist[node] + i.second < dist[i.first]){
                        dist[i.first] = dist[node] + i.second;
                    }
                }
            }
        }
    }
};

int main(){

    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.printAdj();

    int n = 6;
    //topological sort
    unordered_map<int, int> visited;
    stack<int> s;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            g.dfs(i, visited, s);
        }
    }

    int src = 1;
    vector<int> dist(n);
    for(int i=0; i<n; i++){
        dist[i] = INT_MAX;
    }

    g.getShortestPath(src, dist, s);

    for(int i=0; i<n; i++){
        cout<<dist[i]<<" ";
    }
    
    return 0;
}