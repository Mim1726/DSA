#include<bits/stdc++.h>
using namespace std;

//bfs function to calculate the shortest distance from the root
int bfs(vector<vector<int>>& adj,int root,int target){
    queue<int> q;
    vector<bool> visited(adj.size(),false);
    vector<int> distance(adj.size(), -1);//distance from the root node

    visited[root] = true;
    distance[root] = 0;
    q.push(root);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        if(curr == target){
            return distance[curr];
        }

        for(int v: adj[curr]){
            if(!visited[v]){
                visited[v] = true;
                distance[v] = distance[curr]+1;
                q.push(v);
            }
        }
    }
    return -1;
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

    int target = 4;
    int root = 0;

    int ans = bfs(adj,root,target);

    cout << ans << endl;
}
