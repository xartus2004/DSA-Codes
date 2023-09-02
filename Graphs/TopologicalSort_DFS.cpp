//It is for DAG(Directed Acyclic Graph)
//By common sense undirected or/and cyclic graphs can't satisfy the condition below
//These are ordered in a way that if there is an edge between u and v , u appears before v
#include <bits/stdc++.h>
using namespace std;

void DFS(int node,bool visited[],stack<int> &stk,vector<int> adj[])
{
    visited[node]=true;
    for(auto it:adj[node])
        if(!visited[it]) DFS(it,visited,stk,adj);
    stk.push(node);
}

void TopologicalSort_DFS(vector <int> adj[],int V)
{
    bool visited[V]={0};
    stack <int> stk;
    for(int i=0 ; i<V ; i++)
        if(!visited[i]) DFS(i,visited,stk,adj);
}


int main()
{

}