#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int>* adj;
    //Implementing DFS for vertex v in the graph
    bool DFS(int v, vector<bool>& visited, int mother)
    {
        visited[v] = true;
        if (v == mother) {
            return true;
        }
        for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i] && DFS(*i, visited, mother)) {
                return true;
            }
        return false;
    }
public:
    //Constructor
    Graph(int V){
        this->V = V;
        adj = new list<int>[V];
    };

    void addEdge(int v, int w){
        adj[v].push_back(w);
    };

    vector<int> motherVertices(){
        vector<int> mothers;
        for (int i = 0; i < V; i++) {
            vector<bool> visited(V, false);
            if (DFS(i, visited, i)) {
                mothers.push_back(i);
            }
        }
        return mothers;
    }
};

int main()
{
    Graph g(7);
    //Case1
    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(0,3);
    g.addEdge(3,4);

    // //Case2
    // g.addEdge(1,0);
    // g.addEdge(2,1);
    // g.addEdge(0,3);
    // g.addEdge(3,4);

    // //Case3
    // g.addEdge(1,0);
    // g.addEdge(2,1);
    // g.addEdge(0,3);
    // g.addEdge(3,4);
    // g.addEdge(5,3);

    vector<int> mvs = g.motherVertices();
    if(!mvs.empty()) {
        cout << "The mother vertices are: ";
        for(int mv : mvs) {
            cout << mv << ' ';
        }
    } else {
        cout << "There are no mother vertices";
    }

    return 0;
}