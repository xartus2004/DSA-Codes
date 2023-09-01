#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void DFSRec(vector<int> adj[] , int s , bool visited[])
{
    visited[s]=true;
    cout<<s<<"\t";
    for(int u:adj[s])
    {
        if(visited[u]==false)
            DFSRec(adj,u,visited);
    }


}

void DFS(vector<int> adj[],int s,int v)
{
    //Initializing visited array
    bool visited[v+1]={0,};
    DFSRec(adj,s,visited);
}