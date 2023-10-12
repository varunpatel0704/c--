#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class graph{
    public:

        // adjacency list representation --> node is the key and the list of connected edges is the value.
        unordered_map<int, list<int>> adj;

        // method to create edge between two nodes.
        void insertEdge(int u, int v, bool directed){
            // create and edge from u to v
            adj[u].push_back(v);

            // if graph is undirected, then create edge from v to u as well.
            if(!directed){
                adj[v].push_back(u);
            }
        }

        void print(){
            for(auto i: adj){
                cout << i.first << " --> ";
                for(auto j: i.second){
                    cout << j << ", ";
                }cout<<endl;
            }
        }
    
};

int main(){
    cout<<"Enter the number of edges in the graph: ";
    int m;
    cin >> m;

    graph g1;
    for(int i = 0; i<m; i++){
        int u, v;
        cout << "Enter the nodes (u,v): ";
        cin >> u >> v;

        g1.insertEdge(u, v, false);
    }

    g1.print();
    return 0;
}