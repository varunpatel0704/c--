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

int minimumSpanningTree(vector<vector<int>>& edges, int V)
{
    // Kruskal's algorithm.
        
    // pre-requisites - parent array and size array.
    vector<int> size(V, 1);
    
    vector<int> parent(V);
    for(int i=0; i<V; i++)
        parent[i] = i;
    
    // step 1: sort the edges based on their weights.
    sort(edges.begin(), edges.end(), compare);
    
    // step 2: traverse edges array and apply union find 
    int mstCost = 0;
    
    for(auto i: edges){
        int u = i[0];
        int v = i[1];
        int wt = i[2];
        
        // find and compare root nodes of u and v.
        int root1 = find(u, parent);
        int root2 = find(v, parent);
        
        if(root1 == root2)  // when both roots are equal, elements belong to same component 
            continue;       // and hence connecting them will introduce cycle
        
        else{
            mstCost += wt;
            Union(root1, root2, parent, size);
        }
    }
    
    return mstCost;
  
}

int main(){
    vector<vector<int>> edges = {{0, 1, 3},
                                {0, 2, 1},
                                {0, 3, 2},
                                {1, 2, 5},
                                {1, 3, 2},
                                {2, 3, 4}};
    cout<<"mst cost is "<<minimumSpanningTree(edges, 4);
    return 0;
}