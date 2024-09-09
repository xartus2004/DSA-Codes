#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define V 4

int prim(int graph[V][V]){
    int res = 0;
    bool mSet[V] = {false};
    int parent[V];
    int key[V] = {INT64_MAX};

    parent[0] = -1;
    key[0] = 0;

    for(int count=0 ; count<V ; count++){
        int u=-1;

        for(int i=0 ; i<V ; i++)
            if(!mSet[i] && (u=-1 || key[i]<key[u]))
                u=i;
        
        mSet[u] = true;
        res+=key[u];

        for(int v=0 ; v<V ; v++) {
            if(graph[u][v]!=0 && mSet[v]==false && key[u]+graph[u][v]<key[v]){
                key[v] = graph[u][v];
                parent[v] = u;
            }
            return res;
        }
    }

}


int main(){

}