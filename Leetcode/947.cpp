#include <bits/stdc++.h>
#include <iostream>
#define nline "\n";
using namespace std;

class DisjointSet{
public:
  vector<int> rank,parent,size;
  DisjointSet(int n) {
    rank.resize(n+1,0);
    parent.resize(n+1,0);
    size.resize(n+1,0);
    for(int i=0 ; i<=n ; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int findUPar(int node){
    if(parent[node]==node)  return node;
    return parent[node] = findUPar(parent[node]);
  }

  void unionByRank(int u, int v) {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if(ulp_u==ulp_v)  return;
    if(rank[ulp_u]>rank[ulp_v])
      parent[ulp_v] = ulp_u; 
    else if(rank[ulp_v]>rank[ulp_u])
      parent[ulp_u] = ulp_v;
    else{
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
  }
};

s
int main(){
  vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
  //{{0,0},{0,2},{1,1},{2,0},{2,2}}
  cout<<removeStones(stones);
}