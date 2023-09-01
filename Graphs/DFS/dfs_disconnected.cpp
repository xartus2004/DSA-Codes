//O ( V + E )

#include<iostream>
#include <vector>
#include <queue>
using namespace std;

void DFSRec(vector <int> adj[],int s,bool visited[])
{
    visited[s]=true;
    cout<<s<<"\t";
    for(int u:adj[s])
    {
        if(visited[u]==false)
            DFSRec(adj,u,visited);
    }
}

void DFS(vector <int> adj[],int s,int v)
{
    bool visited[v]={0,};
    int count=0;
    for(int i=0 ; i<v ; i++)
    {
        if(visited[i]==false)
        {
            DFSRec(adj,i,visited);
            count++;
        }
    }
}
