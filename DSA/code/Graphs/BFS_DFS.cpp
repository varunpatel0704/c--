#include <iostream>
#include <queue>
#include <unordered_map>
#include <map>
#include <list>
#include <vector>
using namespace std;

class graph{
    public:
        map<int, list<int>> adj;

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

vector<int> BFS(graph g){
    unordered_map<int, bool> visited;// to keep track of visited nodes.
    queue<int> q; 
    q.push(g.adj.begin()->first); // insert the first node into q.
    visited[q.front()] = true;
    vector<int> bfs;
    bfs.push_back(q.front());

    while(!q.empty()){  // BFS is similar to level order traversal

        int temp = q.front();
        q.pop();
        // if(!visited[temp]){
        //     visited[temp] = true;
        //     bfs.push_back(temp);
        // }

        //explore temp by visiting all of its neighbours
        for(auto i: g.adj[temp]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                bfs.push_back(i);
            }
        }
    }
    return bfs;

}

void solve(graph &g, vector<int> &dfs, unordered_map<int, bool> &visited, int node){
    
    cout<<"call received for "<<node;
    
    // start exploring current node.
    visited[node] = true;
    for(auto i: g.adj[node]){
        // mark node as visited and send call for the node
        if(!visited[i]){
            dfs.push_back(i);
            cout<<" ..now sending call for "<<i<<endl;
            solve(g, dfs, visited, i);
            cout<<" ..returned from "<<i;
        }
    }
}

vector<int> DFS(graph &g){
    unordered_map<int, bool> visited;
    vector<int> dfs;

    // root is the first node of the adjacency list.
    int root = g.adj.begin()->first;
    
    dfs.push_back(root);
    for(int i=0; i<g.adj.size(); i++){
        // function is called inside loop to make sure we cover all the nodes(in case of a disconnected graph)
        if(!visited[i])
            solve(g, dfs, visited, root);
    }
    
    
    return dfs;

}

int main(){
    graph g;
    g.insertEdge(1,4,0);
    g.insertEdge(1,2,0);
    g.insertEdge(2,3,0);
    g.insertEdge(2,5,0);
    g.insertEdge(2,8,0);
    g.insertEdge(2,7,0);
    g.insertEdge(3,10,0);
    g.insertEdge(3,9,0);
    g.insertEdge(5,7,0);
    g.insertEdge(5,6,0);
    g.insertEdge(5,8,0);
    g.insertEdge(7,8,0);
    g.insertEdge(4,3,0);
    g.print();

    vector<int> bfs = BFS(g);
    cout<<"bfs-->"<<endl;
    for(auto i: bfs){
        cout<<i<<" ";
    }cout<<endl;


    vector<int> dfs = DFS(g);
    cout<<"dfs-->"<<endl;
    for(auto i: dfs){
        cout<<i<<" ";
    }cout<<endl;



    return 0;
}