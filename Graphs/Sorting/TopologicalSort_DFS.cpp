//It is for DAG(Directed Acyclic Graph)
//By common sense undirected or/and cyclic graphs can't satisfy the condition below
//These are ordered in a way that if there is an edge between u and v , u appears before v

#include <bits/stdc++.h>
using namespace std;

void DFS(int node,bool visited[],stack<int> &stk,vector<int> adj[])
{
    visited[node]=true;
    for(auto it:adj[node])
        if(!visited[it])
            DFS(it,visited,stk,adj);
    stk.push(node);
}

void TopologicalSort_DFS(vector <int> adj[],int V)
{
    bool visited[V]={0};
    stack <int> stk;

    int start;
    cin>>start;
    DFS(start,visited,stk,adj);
    for(int i=0 ; i<V ; i++)
        if(!visited[i] && i!=start) 
            DFS(i,visited,stk,adj);
    
    while(!stk.empty())
    {
        cout<<stk.top()<<"\t";
        stk.pop();
    }
}


int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    // Create an adjacency list with numVertices
    vector<int> adjacencyList[V];

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adjacencyList[u].push_back(v);
    }

    TopologicalSort_DFS(adjacencyList,V);
}