#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>

using namespace std;

void dfs(vector<int> adj[], unordered_map<int, bool> &visited, int node, stack<int> &stk)
{
    visited[node] = true;
    
    for(auto i: adj[node]){
        if(!visited[i]){
            dfs(adj, visited, i, stk);
            
            // push node into stack after returning from recursive call.
            //stk.push(i);
        }
    }
    
    stk.push(node);
}

vector<int> topoSort(int V, vector<int> adj[]) 
{
    // use dfs to solve this.
    unordered_map<int, bool> visited;
    stack<int> stk;
    vector<int> ordering;
    
    // loop required for disconnected graphs
    for(int i=0; i<V; i++){
        if(!visited[i]){
            dfs(adj, visited, i, stk);
            
            // don't forget to insert first element into stack
            // stk.push(i);
        }
            
    }
    
    while(!stk.empty()){
        ordering.push_back(stk.top());
        stk.pop();
    }
    
    return ordering;
}

int main(){
    
    return 0;
}