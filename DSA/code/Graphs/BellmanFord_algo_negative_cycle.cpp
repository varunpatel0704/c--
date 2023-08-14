#include <iostream>
#include <vector>
using namespace std;

int isNegativeWeightCycle(int V, vector<vector<int>>edges){
    // Bellman Ford Algorithm
    
    // initialize the required DS
    vector<int> distance(V, INT64_MAX);
    distance[0] = 0;
    
    // step 1: repeat the process V-1 times
    for(int i = 0 ; i<V-1; i++){
        
        /* visit all the edges in the graph in no particular order
            and update the distance array. */
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            if(distance[u] + wt < distance[v]){
                distance[v] = distance[u] + wt;
            }
        }
    }
    // the distance array now represents shortest paths from source node to other nodes.

    // this part is used for negative cycle detection.

    /* step 2: run the algorithm 1 more time, if any value in distance array is updated,
                then there is a negative cycle in the graph. */
    
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        
        if(distance[u] + wt < distance[v])
            return true;
    }
    
    return false;
}

int main(){
    
    return 0;
}