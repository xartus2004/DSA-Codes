#include <bits/stdc++.h>
using namespace std;

void dfs(int s,int v,vector<vector<int>> &edges,vector<int> visited,stack<int> &finTime)
{
    visited[s]=1;
    vector<int> adj;
    for(auto e:edges){
        if(e[0]==s)
            adj.push_back(e[1]);
    }
    for(auto a:adj){
        dfs(a,v,edges,visited,finTime);
    }
    finTime.push(s);
}

void dfs2(int s,int v,vector<vector<int>> &edges,vector<int> visited)
{
    visited[s]=1;
    vector<int> adj;
    for(auto e:edges){
        if(e[0]==s)
            adj.push_back(e[1]);
    }
    for(auto a:adj){
        dfs2(a,v,edges,visited);
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	stack<int> finTime;
    vector<int> vis(v,0);
    for(int i=0 ; i<v ; i++){
        if(!vis[i]){
            dfs(i,v,edges,vis,finTime);
        }
    }

    for(int i=0 ; i<v ; i++){
        vis[i]=0;
    }
    
    for(int i=0 ; i<edges.size() ; i++){
        int temp=edges[i][0];
        edges[i][0]=edges[i][1];
        edges[i][1]=edges[i][0];
    }

    int scc=v;

    while(!finTime.empty()){
        if(vis[finTime.top()]){
            finTime.pop();
            scc--;
        }
        else{
            dfs2(finTime.top(),v,edges,vis);
        }
    }
    return scc;
}