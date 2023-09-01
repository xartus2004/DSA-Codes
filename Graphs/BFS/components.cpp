#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<int> adj[],int s,bool visited[])
{

    queue<int> q;
    visited[s]=true;
    q.push(s);
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        cout<<u<<"\t";
        for(int v : adj[u])
        {
            if(visited[u]==false)
            {
                visited[u]=true;
                q.push(u);
            }
        }
    }
}

int BFSdis(vector<int> adj[],int v)
{
    bool visited[v+1]={0,};
    int count=0;
    for(int i=0 ; i<v ; v++)
    {
        if(visited[i]==false)
            BFS(adj,i,visited);count++;
    }
    return count;
}