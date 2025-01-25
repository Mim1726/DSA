#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& adj,int x){
    queue<int> q;
    vector<bool> visited(adj.size(),false);

    visited[x]=true;
    q.push(x);

    while(!q.empty()){
        int curr=q.front();
        q.pop();
        cout << curr << " ";

        for(int x: adj[curr]){
            if(!visited[x]){
                visited[x]=true;
                q.push(x);
            }
        }
    }
}

void addEdge(vector<vector<int>>& adj,int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int n=5;

    vector<vector<int>> adj(n);
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,2,4);

    bfs(adj,0);

    return 0;
}
