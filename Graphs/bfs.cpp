#include <iostream>
#include <vector>
#include <queue>
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
            if(visited[u]==false)
            {
                visited[v]=true;
                q.push(u);
            }
        }
    }
}

int main(){

}