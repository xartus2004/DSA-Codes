#include<bits/stdc++.h>

using namespace std;

// Graph 
class Graph {
public:
    unordered_map<string, vector<pair<string, int>>> adjacencyList;

    void addEdge(string u, string v, int cost) {
        adjacencyList[u].emplace_back(v, cost);
        adjacencyList[v].emplace_back(u, cost); 
    }

    vector<pair<string, int>> getNeighbors(string node) {
        return adjacencyList[node];
    }
};
struct comp{
    bool operator()(pair<string,int>& a, pair<string,int>&b)
    {
        return b.second<a.second;
    }
};
//bidirectional
int bidirectionalSearch(Graph& graph, string source, string destination) {
    priority_queue<pair<string, int>, vector<pair<string, int>>, comp> forwardQueue;
    priority_queue<pair<string, int>, vector<pair<string, int>>, comp> backwardQueue;
    unordered_map<string, int> forwardCost;
    unordered_map<string, int> backwardCost;

    forwardQueue.push({source, 0});
    backwardQueue.push({destination, 0});
    forwardCost[source] = 0;
    backwardCost[destination] = 0;

    int minCost = INT_MAX;

    while (!forwardQueue.empty() && !backwardQueue.empty()) {
        pair<string, int> currentForward = forwardQueue.top();
        string nodeF = currentForward.first;
        int forwardCostCurrent = currentForward.second;
        forwardQueue.pop();

        if (backwardCost.find(nodeF) != backwardCost.end()) {
            minCost = min(minCost, forwardCostCurrent + backwardCost[nodeF]);
        }

        for (const auto& neighbor : graph.getNeighbors(nodeF)) {
            string neighborNode = neighbor.first;
            int costF = neighbor.second;
            int newCostF = forwardCostCurrent + costF;

            if (forwardCost.find(neighborNode) == forwardCost.end() || newCostF < forwardCost[neighborNode]) {
                forwardQueue.push({neighborNode, newCostF});
                forwardCost[neighborNode] = newCostF;
            }
        }

        pair<string, int> currentBackward = backwardQueue.top();
        string nodeB = currentBackward.first;
        int backwardCostCurrent = currentBackward.second;
        backwardQueue.pop();

        if (forwardCost.find(nodeB) != forwardCost.end()) {
            minCost = min(minCost, backwardCostCurrent + forwardCost[nodeB]);
        }

        for (const auto& neighbor : graph.getNeighbors(nodeB)) {
            string neighborNode = neighbor.first;
            int costB = neighbor.second;
            int newCostB = backwardCostCurrent + costB;

            if (backwardCost.find(neighborNode) == backwardCost.end() || newCostB < backwardCost[neighborNode]) {
                backwardQueue.push({neighborNode, newCostB});
                backwardCost[neighborNode] = newCostB;
            }
        }
    }

    return (minCost == INT_MAX) ? -1 : minCost;
}

void dfs(string s,string d,Graph& graph,unordered_set<string>& vis,bool& flag)
{
    
    vis.insert(s);
    cout<<s<<" ";
    
    
    if(s==d)
    {
        flag=true;
        return;
    } 
    for(auto it:graph.getNeighbors(s))
    {
        if(flag) return;
        if(vis.find(it.first)==vis.end())
        {
          
        dfs(it.first,d,graph,vis,flag);
           
                      
        }
        
    }
}
    


int main() {
    
    Graph graph;
graph.addEdge("arad","zerind",75);
graph.addEdge("arad","timisoara",118);
graph.addEdge("arad","sibiu",140);
graph.addEdge("zerind","oradea",71);
graph.addEdge("oradea","sibiu",151);
graph.addEdge("timisoara","lugoj",111);
graph.addEdge("lugoj","mehadia",70);
graph.addEdge("mehadia","dobreta",75);
graph.addEdge("dobreta","cralova",120);
graph.addEdge("sibiu","fagaras",99);
graph.addEdge("sibiu","vilcea",80);
graph.addEdge("cralova","vilcea",146);
graph.addEdge("pitesti","vilcea",97);
graph.addEdge("fagaras","bucharest",211);
graph.addEdge("bucharest","giurgiu",90);
graph.addEdge("bucharest","urziceni",85);
graph.addEdge("urziceni","hirsova",98);
graph.addEdge("hirsova","etorie",86);
graph.addEdge("urziceni","vaslui",142);
graph.addEdge("vaslui","lasi",92);
graph.addEdge("lasi","neamt",87);
graph.addEdge("pitesti","bucharest",101);
graph.addEdge("pitesti","cralova",138);

    string source ,destination;
    source="arad";
    destination="vaslui";

    int minCost = bidirectionalSearch(graph, source, destination);

    if (minCost != -1) {
        cout << "Minimum cost from " << source << " to " << destination << ": " << minCost << endl;
    } else {
        cout << "No path found from " << source << " to " << destination << endl;
    }
    unordered_set<string> vis;
    bool flag=false;
    dfs(source,destination,graph,vis,flag);
    return 0;
}