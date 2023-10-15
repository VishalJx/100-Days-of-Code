#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &ver, int vertices, int edges, int source){
    //ajacency list
    unordered_map<int, vector<pair<int, int>>> adj;
    for(int i=0; i<edges; i++){
        int u = ver[i][0];
        int v = ver[i][1];
        int w = ver[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> dist(vertices);
    for(int i=0; i<vertices; i++){
        dist[i] = INT_MAX;
    }

    set<pair<int, int>> st;

    dist[source] = 0;
    st.insert(make_pair(0, source));

    while(!st.empty){
        //fetch top element
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        //remove top element
        st.erase(st.begin());

        //iterate over neighbours/children of top node
        for(auto neighbour: adj[topNode]){
            if(nodeDistance + neighbour.second < dist[neighbour.first]){
                //in the set updation of a particular node is not possible
                //we have to remove the old pair and insert the new pair to simulate updation
                int dest = neighbour.first;
                auto f = st.find(make_pair(dist[dest], dest));
                if(f!=st.end()){
                    st.erase(f);
                }

                //insert the new pair
                dist[dest] = nodeDistance + neighbour.second;
                st.insert(make_pair(dist[dest], dest));
            }
        }
    }

    return dist;
}

int main(){
    
    return 0;
}