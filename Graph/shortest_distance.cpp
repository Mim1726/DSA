#include <bits/stdc++.h>
using namespace std;

// BFS function to calculate the shortest distance from the root node
int bfs(vector<vector<int>>& adj, int root, int target) {
    queue<int> q;
    vector<bool> visited(adj.size(), false);
    vector<int> distance(adj.size(), -1); // Distance from the root node

    visited[root] = true;
    distance[root] = 0;
    q.push(root);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == target) {
            return distance[curr]; // Return the distance if the target is reached
        }

        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                distance[neighbor] = distance[curr] + 1;
                q.push(neighbor);
            }
        }
    }

    return -1; // Return -1 if the target node is not reachable
}

// Function to add an edge in the adjacency list
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // Assuming an undirected graph
}

int main() {
    int n = 5; // Number of nodes

    vector<vector<int>> adj(n);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);

    int target = 4; // Target node to find the shortest distance
    int root = 0;   // Root node

    int result = bfs(adj, root, target);
    if (result != -1) {
        cout << "Shortest distance from node " << root << " to node " << target << ": " << result << endl;
    } else {
        cout << "Node " << target << " is not reachable from node " << root << endl;
    }

    return 0;
}
