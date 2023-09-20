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

int main()
{   
    int v=6;
    vector<int> arr[]={{2,3,4},{2,3},{0,1},{0,1,4},{0,3,5},{4}};
    DFS(arr,0,v);
}