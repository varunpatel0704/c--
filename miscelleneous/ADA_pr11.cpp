#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int> &a, vector<int> &b){
    return (a[2] < b[2]);
}

int find(int node, vector<int> &parent){
    // traverse the parent array till a self loop is found.
    int temp = node;
    while(temp != parent[temp])  // <-- condition indicates self-loop
        temp = parent[temp];
    
    int root = temp;
    temp = node;
    
    // path compression
    while(temp != root){         // traverse back till root node and connect each node directly
        int next = parent[temp]; // to root node in the process for amortized constant complexity
        parent[temp] = root;    
        temp = next;
    }
    
    return root;
  }

void Union(int root1, int root2, vector<int> &parent, vector<int> &size){
    
    // merge smaller component into larger one
    if(size[root1] > size[root2]){
          parent[root2] = root1;
          size[root1] += size[root2];
    }
        
    else{
        parent[root1] = root2;
        size[root2] += size[root1];
    }
}

int minimumSpanningTree(vector<vector<int>>& edges, int V, vector<vector<int>> &ans)
{
    // Kruskal's algorithm.
        
    // pre-requisites - parent array and size array.
    vector<int> size(V, 1);
    
    vector<int> parent(V);
    for(int i=0; i<V; i++)
        parent[i] = i;
    
    // step 1: sort the edges based on their weights.
    sort(edges.begin(), edges.end(), compare);
    
    // step 2: traverse edges array and apply union find.
    int mstCost = 0;
    
    for(auto edge: edges){
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        
        // find and compare root nodes of u and v.
        int root1 = find(u, parent);
        int root2 = find(v, parent);
        
        if(root1 == root2)  // when both roots are equal, elements belong to same component 
            continue;       // and hence connecting them will introduce cycle
        
        else{
            ans.push_back(edge);
            mstCost += wt;
            Union(root1, root2, parent, size);
        }
    }
    
    return mstCost;
  
}

int main(){
    vector<vector<int>> edges = {{0, 5, 10},
                                 {0, 1, 28},
                                 {5, 4, 25},
                                 {4, 6, 24},
                                 {6, 1, 14},
                                 {3, 2, 12},
                                 {3, 4, 22},
                                 {1, 2, 16},
                                 {6, 3, 18}};
    vector<vector<int>> mst;
    int cost = minimumSpanningTree(edges, 7, mst);
    cout<<"Finding MST using Kruskal's algorithm..."<<endl;
    cout<<"\nEdges in the MST:"<<endl;
    for(auto edge: mst){
        cout << edge[0] << "-" << edge[1] << endl;
    }
    cout<<"\nCost of MST is: "<<cost<<endl;
    return 0;
}