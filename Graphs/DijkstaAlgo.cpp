//Its a Greedy Algorithm
//It is a Greedy Algo
//It may or may not give correct answer for Negative edges
// O(n^2) because n vertices are to be relaxed and each vertex can be connected to at max n-1 vertices(complete graph)

#include <bits/stdc++.h> 
using namespace std; 
#define V 4

vector<int> djikstraAlgo(int graph[V][V],int src) 
{ 

	vector <int> dist(V,INT_MAX);
	dist[src]=0;
	vector <bool> finalised(V,false);

	for (int count = 0; count < V-1 ; count++) 
	{ 
		int u = -1; 
		for(int i=0;i<V;i++)
		    if(!finalised[i] && (u==-1||dist[i]<dist[u]))
		        u=i;
		finalised[u] = true;
		for (int v = 0; v < V; v++)
			//Relaxation
			if (graph[u][v]!=0 && finalised[v] == false && (dist[u]+graph[u][v]) < dist[v]) 
				dist[v] = dist[u]+graph[u][v]; 
	}
    return dist;
}

int main() 
{ 
	int graph[V][V] = { { 0, 50, 100, 0},
						{ 50, 0, 30, 200 },
						{ 100, 30, 0, 20 },
						{ 0, 200, 20, 0 },};
	for(int x: djikstraAlgo(graph,0))
	    cout<<x<<" ";
	return 0; 
} 
