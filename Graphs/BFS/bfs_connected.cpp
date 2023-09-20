#include <bits/stdc++.h>
using namespace std;

void BFS(vector <int> adj[],int v,int s)
{
    bool visited[v+1]={0,};
    queue <int> q;
    visited[s]=1;
    q.push(s);
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        cout<<u<<"\t";
        for(int v:adj[u])
        {
            if(visited[v]==false)
            {
                visited[v]=true;
                q.push(v);
            }
        }
    }
}

int main()
{   
    int v=6;
    vector<int> arr[]={{2,3,4},{2,3},{0,1},{0,1,4},{0,3,5},{4}};
    BFS(arr,v,0);
}