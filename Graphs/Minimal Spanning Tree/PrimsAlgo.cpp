#include <bits/stdc++.h> 
using namespace std; 
#define V 4

void printMST(int parent[], int graph[V][V])
{ 
	int minCost=0;
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << "\t"<<"-> "<< graph[i][parent[i]] << " \n";
        minCost+=graph[i][parent[i]];
    }
}

int primsAlgo(int graph[V][V]) 
{
    int parent[V];		//Parent of node 'i'
	int key[V];			//key is the the weight of the edge which connects i with its parent
	int res=0; 
	fill(key,key+V,INT_MAX);
	bool mSet[V]={false};
	key[0]=0;
	parent[0] =-1;

	for (int count = 0; count < V ; count++) 
	{ 
		int u = -1; 

		for(int i=0;i<V;i++)
			if(!mSet[i]&&(u==-1||key[i]<key[u]))
				u=i;
		mSet[u] = true; 
		res+=key[u];
		for (int v = 0; v < V; v++) 
			if (graph[u][v]!=0 && mSet[v] == false && (key[u]+graph[u][v]) < key[v])
			{
				key[v] = graph[u][v];
				parent[v]=u;
			}
	}
	printMST(parent, graph);
	return res;
}

int main() 
{ 
	int graph[V][V] = { { 0, 5, 8, 0}, 
						{ 5, 0, 10, 15 }, 
						{ 8, 10, 0, 20 }, 
						{ 0, 15, 20, 0 },}; 

	cout<<primsAlgo(graph); 

	return 0; 
} 
