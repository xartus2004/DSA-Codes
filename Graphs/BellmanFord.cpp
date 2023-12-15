#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V,vector<vector<int>>&edges,int s)
{
    vector<int> dist(V,INT_MAX);
    dist[s]=0;
    for(int i=0 ; i<V-1 ; i++)
    {
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u]!=INT_MAX && dist[u]+wt<dist[v])
                dist[v]=dist[u]+wt;
        }
    }

    //Nth relaxation will help us know if there is negative edge
    for(auto it:edges)
    {
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        if(dist[u]!=0 && dist[u]+wt<dist[v])
            dist[v]=dist[u]+wt;
    }
}