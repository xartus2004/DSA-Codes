/*
We are given a map of cities connected with each other via cable lines such that there is no cycle between any two cities. We need to find the maximum length of cable between any two cities for given city map. 

Input : n = 6  
        1 2 3  // Cable length from 1 to 2 (or 2 to 1) is 3
        2 3 4
        2 6 2
        6 4 6
        6 5 5
Output: maximum length of cable = 12
*/

#include <bits/stdc++.h>
using namespace std;

void DFS(vector<pair<int,int>> graph[],int s,int prev_len,int *max_len,vector<bool> &visited){
    visited[s] = true;
    int curr_len=0;
    pair<int,int> adj;

    for(int i=0 ; i<graph[s].size() ; i++){
        adj = graph[s][i];
        if(!visited[adj.first]){
            curr_len=prev_len+adj.second;
            DFS(graph,adj.first,curr_len,max_len,visited);
        }

        if((*max_len)<curr_len){
            *max_len=curr_len;
        }
        curr_len = 0;
    }
}

int long_cable(vector<pair<int,int>> graph[],int n){
    int max_len=INT_MIN;
    for(int i=0 ; i<n ; i++){
        vector<bool> visited(n+1,false);
        DFS(graph,i,0,&max_len,visited);
    }
    return max_len;
}

int main(){
    int n = 6;
 
    vector< pair<int,int> > graph[n+1];
 
    // create undirected graph
    // first edge
    graph[1].push_back(make_pair(2, 3));
    graph[2].push_back(make_pair(1, 3));
 
    // second edge
    graph[2].push_back(make_pair(3, 4));
    graph[3].push_back(make_pair(2, 4));
 
    // third edge
    graph[2].push_back(make_pair(6, 2));
    graph[6].push_back(make_pair(2, 2));
 
    // fourth edge
    graph[4].push_back(make_pair(6, 6));
    graph[6].push_back(make_pair(4, 6));
 
    // fifth edge
    graph[5].push_back(make_pair(6, 5));
    graph[6].push_back(make_pair(5, 5));
 
    cout << "Maximum length of cable = "
         << long_cable(graph, n);
 
    return 0;
}