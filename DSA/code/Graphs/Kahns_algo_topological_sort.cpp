#include <iostream>
#include <queue>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[]) 
{
    // required DS -> queue, vector for indegree and ans vector.
    vector<int> ordering;
    vector<int> inDegree(V, 0);
    queue<int> q;
    
    // calculate in-degree of each node.
    for(int i=0; i<V; i++){
        for(auto j: adj[i]){
            inDegree[j]++;
        }
    }
    
    // initialize queue with nodes with in-degree 0.
    for(int i=0; i<V; i++){
        if(inDegree[i] == 0)
            q.push(i);
    }
    
    // process till queue is not empty.
    while(!q.empty()){
        // pop front and insert into topological ordering
        int front = q.front();
        q.pop();
        
        ordering.push_back(front);
        
        // decrement in-degree of neighbour nodes by one
        for(auto i: adj[front]){
            inDegree[i]--;
            if(inDegree[i] == 0)
                q.push(i);
        }
    }

    return ordering;
}

int main(){
    
    return 0;
}