#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

class graph{
    public:

        // adjacency list representation --> node is the key and the list of connected vertices is the value.
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

//BFS
void BFS(graph &g, vector<int> &ans, int s){
    unordered_map<int, bool> visited;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for(auto neighbour: g.adj[front]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}

//DFS
void DFS(graph &g, vector<int> &ans, int s, unordered_map<int, bool> &visited){
    visited[s] = true;
    for(auto neighbour: g.adj[s]){
        if(!visited[neighbour]){
            ans.push_back(neighbour);
            DFS(g, ans, neighbour, visited);
        }
    }
}


int main(){
    cout<<"Enter the number of edges in the graph: ";
    int m;
    cin >> m;
    cout<<endl;
    graph g1;
    for(int i = 0; i<m; i++){
        int u, v;
        cout << "Enter the edge (u,v): ";
        cin >> u >> v;

        g1.insertEdge(u, v, false);
    }
    cout<<"\nAdjacency list of the given graph is: "<<endl;
    g1.print();

    vector<int> bfs;
    //BFS
    BFS(g1, bfs, 2);
    cout<<"\nBFS traversal of the given graph is: "<<endl;
    for(auto item: bfs){
        cout<<item<<", ";
    }cout<<endl;
   
    //DFS
    vector<int> dfs;
    unordered_map<int, bool> visited;
    dfs.push_back(2);
    visited[2] = true;
    DFS(g1, dfs, 2, visited);

    cout<<"\nDFS traversal of the given graph is: "<<endl;
    for(auto item: dfs){
        cout<<item<<", ";
    }cout<<endl;

    return 0;
}