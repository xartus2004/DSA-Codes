#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int visited[],vector<int> adj[])
{
	visited[node]=1;
	for(auto it:adj[node])
	    if(!visited[it])
            dfs(it,visited,adj);
	
}

void motherVertex(vector<int>  adj[],vector<int> &moth,int v)
{
	for(int i=0;i<v;i++){
        int visited[v]={0};
	    bool k=true;
		dfs(i,visited,adj);
		for(int i=0;i<v;i++)
			if(visited[i]!=1) k=false;
	    if(k) moth.push_back(i);
	}
}

int main()
{   
    int v,e;
    cout<<"Enter the no of vertices and edges:";
    cin>>v>>e;
    
	vector<int> adj[v];
	vector<int> res;
	
	for(int i=0;i<e;i++){ 
        int a,b;
		cout<<"Enter edges:";
		cin>>a>>b;
		adj[a].push_back(b);
	}
	motherVertex(adj,res,v);

	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
}