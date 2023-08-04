#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;


// CYCLE DETECTION USING BFS IN UNDIRECTED GRAPH. 
bool bfs(vector<vector<int>> adj, unordered_map<int, bool> &visited, int node){
    // this is merely a modifies BFS

    queue<int> q;
    unordered_map<int,int> parent;
    
    // initialize q and map
    q.push(node);
    visited[node] = true;
    parent[node] = -1;
    
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        
        // explore temp.
        for(auto i: adj[temp]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                parent[i] = temp;
            }
            
            else if(visited[i] && parent[temp] != i){
                return true;
            }
        }
        
    }
    
    return false;
}

bool isCycle(int V, vector<vector<int>> adj) {
    // we will use bfs traversal to detect cycle.
    
    // create required data structures.
    unordered_map<int, bool> visited;
    int node = 0;
    bool ans;
    // loop is required to cover all the nodes since graph can be disconnected.
    for(int i=0; i<V; i++){
        if(!visited[i]){
            ans = bfs(adj, visited, i);
            if(ans)
                return true;
        }
    }
    
    
    return false;
}


// CYCLE DETECTION USING DFS IN UNDIRECTED GRAPH.
bool dfs(vector<int> adj[], unordered_map<int, bool> &visited, int node, int parent){
    
    visited[node] = true;
    // start exploring node.
    for(auto i: adj[node]){
        if(!visited[i]){
            // parent[i] = node;
            bool ans = dfs(adj, visited, i, node);
            if(ans)
                return ans;
        }
        
        else if(visited[i] && parent !=i)
            return true;
    }
    return false;
    
}

bool isCycle(int V, vector<int> adj[]) {
    // we will use bfs traversal to detect cycle.
    
    // create required data structures.
    unordered_map<int, bool> visited;
    // unordered_map<int,int> parent;
    int parent = -1;
    bool ans;
    // loop is required to cover all the nodes since graph can be disconnected.

    for(int i=0; i<V; i++){
        if(!visited[i]){
            // parent[i] = -1;
            ans = dfs(adj, visited, i, parent);
            if(ans)
                return true;
        }
    }
    
    
    return false;
}

int main(){
    
    return 0;
}