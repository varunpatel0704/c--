#include <iostream>
#include <queue>
using namespace std;

// CYCLE DETECTION IN DIRECTED GRAPH USING DFS
bool dfs(vector<int> adj[], vector<bool> &visited, vector<bool> &called, int node)
{
    // mark node as visited.
    visited[node] = true;
    called[node] = true;
    // explore node.
    for(auto i: adj[node]){
        if(!visited[i]){
            bool ans = dfs(adj, visited, called, i);
            if(ans)
                return true;
        }
        
        else if(called[i]) // call for neighbour repeated in current stack -> cycle present
            return true;
    }
    
    //don't forget to mark dfs call as univisted after returning
    // because the calls will be diverted to different path now
    
    //backtrack
    called[node] = false;
    return false;
        
}


bool isCyclic(int V, vector<int> adj[]) {
    // using dfs.
    // we will slightly modify dfs algo by adding a map for dfs calls
    // if a dfs call is repeated in a recursive call stack, it means cycle is present.
    
    vector<bool> visited(V,0); // or unordered_map<int, bool> visited;
    vector<bool> called(V,0);  // or unordered_map<int, bool> called;
    bool ans;
    
    for(int i=0; i<V; i++){
        if(!visited[i]){
            ans = dfs(adj, visited, called, i);
            if(ans)
                return true;
        }
    }
    
    return false;
    
}


// CYCLE DETECTION IN DIRECTED GRAPH USING TOPOLOGICAL SORT
bool isCyclic(int V, vector<int> adj[]) {
    // modified topological sort algo
    vector<int> inDegree(V, 0);
    
    // calculate in-degree of each node.
    for(int i=0; i<V; i++){
        
        for(auto j: adj[i]){
            inDegree[j]++;
        }
    }
    
    
    // insert nodes with in-degree 0 into the queue.
    queue<int> q;
    for(int i=0; i<V; i++){
        if(inDegree[i] == 0)
            q.push(i);
    }
    
    
    // topological sort.
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        for(auto i: adj[front]){
            inDegree[i]--;
            if(inDegree[i] == 0)
                q.push(i);
        }
    }
    
    
    // after performing topological sort, if there is any node with
    // in-degree != 0, it indicates a cycle.
    for(int i=0; i<V; i++){
        if(inDegree[i] != 0)
            return 1;
    }
    
    return 0;
}


int main(){
    
    return 0;
}