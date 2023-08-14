#include <iostream>
#include <queue>
using namespace std;

/* The graph is assumed to be connected. This should technically work for disconnected graphs as well, the distance for
   unreachable nodes will be INT64_MAX in case of disconnected graphs*/ 



class compare{
    public:
    bool operator() (pair<int, int> a, pair<int,int> b){
        return (a.second > b.second);
    }
};

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // step 1: inititalize required DS -> distance array and priority queue.
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    vector<int> distance(V, INT64_MAX);
    distance[S] = 0;
    
    // initially insert source node with distance zero into the min heap.
    pq.push({S,0});
    
    // step 2: process till min heap not empty.
    while(!pq.empty()){
        int top = pq.top().first;
        pq.pop();
        
        // relax the neighbouring nodes whenever possible.
        for(auto i: adj[top]){
            int nbr = i[0];
            int wt = i[1];
            
            if(distance[top] + wt < distance[nbr]){
                // relax the node
                distance[nbr] = distance[top] + wt;
                
                // insert the updated pair into min heap.
                pq.push({nbr, distance[nbr]});
            }
        }
    }
    
    return distance;
}

int main(){
    
    return 0;
}