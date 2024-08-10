#include <bits/stdc++.h>
using namespace std;

#define V 6 // number of vertices

// Edge structure
struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

// Function to perform DFS and check connectivity
void DFS(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v, adj, visited);
        }
    }
}
//graph traversal

// Function to check if the graph is connected
bool isConnectedGraph(vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    int node = -1; // starting node
    for (int i = 0; i < V; i++) {
        if (!adj[i].empty()) {
            node = i;
            break;
        }
    }
    if (node == -1) return true; // No edges, trivially connected

    DFS(node, adj, visited);
    for (int i = 0; i < V; i++) {
        if (!adj[i].empty() && !visited[i]) {
            return false;
        }
    }
    return true;
}

// Reverse delete algorithm to find MST
vector<Edge> reverseDeleteMST(vector<Edge>& edges) {
    // Sort edges in descending order of weights
    sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) {
        return a.weight > b.weight; //descending order
    });

    // Initial adjacency list
    vector<vector<int> > adj(V);
    for (auto& edge : edges) {
        adj[edge.u].push_back(edge.v);
        adj[edge.v].push_back(edge.u);
    }

    // Iterate through the edges in descending order
    for (auto& edge : edges) {
        // Remove edge from adjacency list
        adj[edge.u].erase(remove(adj[edge.u].begin(), adj[edge.u].end(), edge.v), adj[edge.u].end());
        adj[edge.v].erase(remove(adj[edge.v].begin(), adj[edge.v].end(), edge.u), adj[edge.v].end());

        // Check if the graph is still connected
        if (!isConnectedGraph(adj)) {
            // If not connected, add the edge back
            adj[edge.u].push_back(edge.v);
            adj[edge.v].push_back(edge.u); //add back to the graph
        } else {
            // If connected, edge remains removed
            cout << "Removed edge: " << edge.u << " - " << edge.v << " with weight " << edge.weight << endl;
        }
    }

    // Collect the remaining edges to form the MST
    vector<Edge> mst;
    for (auto& edge : edges) {
        if (find(adj[edge.u].begin(), adj[edge.u].end(), edge.v) != adj[edge.u].end()) {
            mst.push_back(edge);
        }
    }

    return mst;
}

int main() {
    vector<Edge> edges = {
        {0, 1, 4}, {0, 2, 4}, {1, 2, 2}, {1, 3, 5}, {2, 3, 8}, {2, 4, 10}, {3, 4, 2}, {3, 5, 6}, {4, 5, 3}
    };

    cout << "Initial graph edges:" << endl;
    for (auto& edge : edges) {
        cout << edge.u << " - " << edge.v << " with weight " << edge.weight << endl;
    }

    vector<Edge> mst = reverseDeleteMST(edges);

    cout << "MST edges:" << endl;
    for (auto& edge : mst) {
        cout << edge.u << " - " << edge.v << " with weight " << edge.weight << endl;
    }

    return 0;
}
