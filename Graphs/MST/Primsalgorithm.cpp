#include <bits/stdc++.h>
using namespace std;
 
 //Number of vertices in graph
#define V 5
 
 //Function to return minimum key value from set of vertices not included in MST
int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX;
    int min_index;
 
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
 
    return min_index;
}
 
void printMST(int parent[], int graph[V][V])
{ int minCost=0;
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << "\t"<<"-> "<< graph[i][parent[i]] << " \n";
        minCost+=graph[i][parent[i]];
    }
    cout<<"The cost of MST: "<<minCost;
        
}
 

void primMST(int graph[V][V])
{
    int parent[V];
    int key[V]={INT_MAX,};
    bool mstSet[V]={0,};

    key[0] = 0;
    parent[0] =-1;
 
    for (int count = 0; count < V - 1; count++) 
	{
        int u = minKey(key, mstSet);
        mstSet[u] = true;
 
        for(int v=0;v<V;v++)
        {
            if(graph[u][v]!=0 && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }
     printMST(parent, graph);
}

int main()
{
    int graph[V][V] = { { 0, 4, 5, 0, 0 },
                        { 4, 0, 0, 2, 0 },
                        { 5, 0, 0, 6, 1 },
                        { 0, 2, 6, 0, 3 },
                        { 0, 0, 1, 3, 0 } };
 
    primMST(graph);
 
    return 0;
}
 