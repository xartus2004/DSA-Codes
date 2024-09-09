#include <bits/stdc++.h>
using namespace std;

void printAdjacencyList(const vector<vector<int>>& adjList) {
    for (int i = 0; i < adjList.size(); ++i) {
        cout << "Adjacency list for vertex " << i << ": ";
        for (int j = 0; j < adjList[i].size(); ++j) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
}


vector<int> TopologicalSort(vector <int> adj[],int V)
{
    int Indegree[V]={0};
    for(int i=0 ; i<V ; i++)
    {
        for(auto it:adj[i])
            Indegree[it]++;
    }

    queue <int> q;

    for(int i=0 ; i<V ; i++)
        if(Indegree[i]==0)
            q.push(i);

    vector <int> topo;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it : adj[node])
        {
            Indegree[it]--;
            if(Indegree[it]==0)
                q.push(it);
        }
    }

    for(auto it:topo)
        cout<<it<<"\t";
    // return topo;
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
    vector<int> topo=TopologicalSort(adjacencyList,V);
    
    for(auto it:topo)
        cout<<it<<"\t";

    return 0;

}