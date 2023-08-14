#include <iostream>
#include <queue>
using namespace std;


class compare{      // custom comparator for pq(minHeap)
    public:
    bool operator() (pair<int, int> a, pair<int, int> b){
        return (a.second > b.second);
    }
};

//Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTreeCost(int V, vector<vector<int>> adj[])   /* adj[i] contains vectors of size 2 and each vector contains --> {v, wt} (similar to list of pairs corresponding to each node) */
{
    // initialize visited array and priority queue
    vector<bool> visited(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    
    // initially, node 0 with cost 0 is inserted to kick start the algorithm.
    pq.push({0,0});
    
    // keep processing untill every node is visited or pq is empty.
    int cnt = 0, mstCost = 0;
    
    while(cnt != V && !pq.empty()){
        pair<int, int> top = pq.top();
        pq.pop();
        
        int node = top.first, cost = top.second;

        // ignore visited nodes
        if(visited[node])
            continue;
        
        cnt++;              // increment no of visited nodes
        mstCost += cost;    // add the edge cost to MST cost.
        
        visited[node] = true; 
        for(auto i: adj[node]){
            int v = i[0];
            int wt = i[1];
            
            if(!visited[v]){        // insert unvisited neighbours to pq along with their edge costs.
                pq.push({v, wt});
            }
        }
    }
    
    return mstCost; 
}

int main(){
    
    return 0;
}