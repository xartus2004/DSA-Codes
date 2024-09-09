#include <bits/stdc++.h>
using namespace std; 

class Solution 
{
    public:
	int findMotherVertex(int V, vector<int>adj[])
	{
	    bool vis[V];
	    int i, j, c=0;
	    stack<int> s;
	    
	    for(i=0; i<V; i++){
	        vis[i]=false;
	    }
	    
	    for(i=0; i<V; i++){
	        if(vis[i]==false)
	        {
	            dfs(i, adj, vis, s);
	        }
	    }
	    
	    for(i=0; i<V; i++){
	        vis[i]=false;
	    }
	    
	    checkIfMotherVertexDfs(s.top(), adj, vis, c);
	    
	    if(c==V){
	        return s.top();
	    }else{
	        return -1;
	    }
	}
	
	void checkIfMotherVertexDfs(int i, vector<int> adj[], bool vis[], int & c)
	{
	    vis[i]=true;
	    c++;
	    
	    for(auto x : adj[i]){
	        if(vis[x]==false){
	            checkIfMotherVertexDfs(x, adj, vis, c);
	        }
	    }
	}
	
	void dfs(int i, vector<int> adj[], bool vis[], stack<int> & s)
	{
	    vis[i]=true;
	    
	    for(auto x : adj[i]){
	        if(vis[x]==false){
	            dfs(x, adj, vis, s);
	        }
	    }
	    
	    s.push(i);
	}

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}