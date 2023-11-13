// #include <iostream>
// #include <unordered_map>
// #include <queue>
// using namespace std;

// class compare{
//     public: 
//         bool operator() (vector<int> &a, vector<int> &b){
//             return a[2] > b[2];
//         }
// };

// void addEdge(unordered_map<int, vector<vector<int>>> &adj, int u, int v, int wt){
//     adj[u].push_back({v, wt});
//     adj[v].push_back({u, wt});
// }

// int minimumSpanningTree(unordered_map<int, vector<vector<int>>> adj, vector<vector<int>> &ans, int n){
//     vector<bool> visited(n, 0);
//     priority_queue<vector<int>, vector<vector<int>>, compare> minHeap;

//     minHeap.push({0, 0, 0});
//     visited[0] = true;
//     int count = 0, mstCost = 0;

//     while(count != n && !minHeap.empty()){
//         vector<int> edge = minHeap.top();
//         minHeap.pop();

//         int u = edge[0], v = edge[1], wt = edge[2];
//         if(visited[v])
//             continue;
        
//         visited[v] = true;
//         count++;
//         mstCost += wt;
//         ans.push_back(edge);
//         for(auto neighbour: adj[v]){
//             int v = neighbour[0];
//             int wt = neighbour[1];

//             if(!visited[v])
//                 minHeap.push({u, v, wt});
//         }
//     }
//     return mstCost;
// }

// int main(){
//     unordered_map<int, vector<vector<int>>> adj;    
//     vector<vector<int>> ans;
//     addEdge(adj, 0, 5, 10);
//     addEdge(adj, 0, 1, 28);
//     addEdge(adj, 1, 2, 16);
//     addEdge(adj, 2, 3, 12);
//     addEdge(adj, 4, 3, 22);
//     addEdge(adj, 5, 4, 25);
//     addEdge(adj, 6, 4, 24);
//     addEdge(adj, 6, 1, 14);
//     addEdge(adj, 6, 3, 18);

//     int minimumSpanningTreeCost = minimumSpanningTree(adj, ans, 6);
//     cout<<minimumSpanningTreeCost;
//     return 0;
// }


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
int spanningTreeCost(int V, vector<vector<int>> adj[], vector<vector<int>> &ans)   /* adj[i] contains vectors of size 2 and each vector contains --> {v, wt} (similar to list of pairs corresponding to each node) */
{
    // initialize visited array and priority queue
    vector<int> parent(V, -1);
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
        ans.push_back({parent[node], node});
        visited[node] = true; 

        for(auto i: adj[node]){
            int v = i[0];
            int wt = i[1];
            if(!visited[v]){        // insert unvisited neighbours to pq along with their edge costs.
                pq.push({v, wt});
                parent[v] = node;
            }
        }
    }
    
    return mstCost; 
}

int main(){
    vector<vector<int>> adj[] = {{{5, 10}, {1, 28}}, 
                                 {{2, 16}, {0, 28}, {6, 14}},
                                 {{1, 16}, {3, 12}},
                                 {{6, 18}, {4,22}, {2, 12}},
                                 {{6, 24}, {3, 22}, {5,25}},
                                 {{0, 10}, {4, 25}},
                                 {{4, 24}, {1, 14}, {3, 18}}};
    vector<vector<int>> mst;

    int cost = spanningTreeCost(7, adj, mst);
    cout<<"Finding MST using Prim's algorithm...\n"<<endl;
    cout<<"Edges in the MST:"<<endl;
    for(int i=1; i<mst.size(); i++){        
        cout<<mst[i][0]<<"-"<<mst[i][1]<<endl;        
    }
    cout<<"\nCost of MST: "<<cost<<endl;
    return 0;
}