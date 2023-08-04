#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

// SINGLE SOURCE SHORTEST PATH IN A DIRECTED ACYCLIC GRAPH USING TOPOLOGICAL SORT

void dfs(int node, vector<pair<int, int>> adj[], stack<int> &ordering, vector<int> &visited)
{
    visited[node] = true;
    for (auto it : adj[node])
    {
        if (visited[it.first] != 1)
            dfs(it.first, adj, ordering, visited);
    }
    ordering.push(node);
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    vector<pair<int, int>> adj[N];
    for (int i = 0; i < M; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }

    stack<int> ordering;
    vector<int> visited(N, 0);
    int src = 0;

    for (int i = 0; i < N; i++)
    {
        if (visited[i] != 1)
            dfs(i, adj, ordering, visited);
    }

    vector<int> dist(N, INT64_MAX);
    dist[src] = 0;

    while (!ordering.empty())
    {
        int node = ordering.top();
        ordering.pop();

        for (auto i : adj[node])
        {
            int v = i.first;
            int wt = i.second;
            if (dist[node] + wt < dist[v])
            {
                dist[v] = wt + dist[node];
            }
        }
    }

    for (int i = 0; i < dist.size(); i++)
    {
        if (dist[i] == INT64_MAX)
            dist[i] = -1;
    }
    return dist;
}

int main(){
    
    return 0;
}