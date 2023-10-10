#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
        //Adjacency List
        unordered_map<int, list<int> > adj;

        void addEdge(int u, int v, bool dir){
            //dir = 0 -> undirected
            //dir = 1 -> directed

            //add v to u's list(edge from u to v)
            adj[u].push_back(v);
            if(dir == 0){ //if undirected
                adj[v].push_back(u);
            }
        }

        void print(){
            cout<<"Adjacency List: "<<endl;
            for(auto i: adj){
                cout<<i.first<<"->";
                for(auto j: i.second){
                    cout<<j<<", ";
                }
                cout<<endl;
            }
        }

};

int main(){

    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;

    int m;
    cout<<"Enter number of edges: ";
    cin>>m;

    Graph g;

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        //undirected graph
        g.addEdge(u,v,0);
    }

    //print the adjacency list
    g.print();
    
    return 0;
}