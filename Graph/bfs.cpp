#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& adj,int x){
    queue<int> q;
    vector<bool> visited(adj.size(),false);

    visited[x] = true;
    q.push(x);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for(int v: adj[curr]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void add_edge(vector<vector<int>>& adj,int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int n=5;
    vector<vector<int>> adj(n);

    add_edge(adj,0,1);
    add_edge(adj,0,2);
    add_edge(adj,1,3);
    add_edge(adj,1,4);
    add_edge(adj,2,4);

    bfs(adj,0);

    return 0;
}
