#include <bits/stdc++.h>
using namespace std;
#define V 5 // number of vertices (from 1 to V)

// a recursive function to traverse the graph without considering the ith vertex and its associated edges
// take vertex i out of the considered scope
void DFS(vector<int> adj[], vector<bool>& visited, int i, int curr) {
    visited[curr] = true;
    for (auto x : adj[curr]) {
        if (x != i) {
            if (!visited[x]) {
                DFS(adj, visited, i, x);
            }
        }
    }
}

// function to find Articulation Points in the graph
bool has_Articulation_Point(vector<int> adj[]) {
    // Iterating over all the vertices and for each vertex i
    // remove the vertex and check whether the graph remains connected
    for (int i = 1; i <= V; i++) {
        // keep track of the component of the graph
        int component = 0;
        vector<bool> visited(V + 1, false); // starting from 1 to V
        for (int j = 1; j <= V; j++) { // the curr vertex in DFS
            if (j != i) { // check to REMOVE i
                if (!visited[j]) {
                    component++;
                    DFS(adj, visited, i, j);
                }
            }
            if (component > 1) return true; // check connectivity
        }
    }
    return false;
}

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    vector<int> adj[V + 1];
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);

    cout << "Is the graph Biconnected: " << (has_Articulation_Point(adj) ? "NO" : "YES") << endl;
    return 0;
}
