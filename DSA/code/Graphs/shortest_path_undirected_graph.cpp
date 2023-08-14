#include<bits/stdc++.h>

using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int N , int M, int src , int dest){
	
	/* shortest path in undirected unweighted graph can be found using  
		modified breadth first search algorithm. 
		We will find the parent(immediate predecessor) of each node
		and with it's help we can find the shortest path by backtracking
		from destination node to source node by connecting parent nodes. */
	
	unordered_map<int, list<int>> adj;
	
	// construct the adjacency list.
	for(int i=0; i<M; i++){
		int u=edges[i].first;
		int v=edges[i].second;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	unordered_map<int, bool> visited;
	unordered_map<int, int> parent;
	
	// bfs
	queue<int> q;
	q.push(src);
	visited[src] = true;
	parent[src]=-1;
	
	while(!q.empty()){
		int front = q.front();
		q.pop();
		
		for(auto i: adj[front]){
			if(!visited[i]){
				visited[i] = true;
				parent[i] = front;
				q.push(i);
			}
		}
	}


	vector<int> path;
	int temp = dest;
	path.push_back(dest);
	
	while(temp != src){
		temp = parent[temp];
		path.push_back(temp);
	}

	reverse(path.begin(), path.end());
	return path;
	
}

int main(){
    
    return 0;
}