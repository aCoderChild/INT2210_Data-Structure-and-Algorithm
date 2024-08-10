/*
1. Need to find a minimum spanning tree of a graph using Kruskal's algorithm
or Prim's algorithm, denote the MST as T
2. Next, iterate throu h each edge e in the graph. For each edge e, we remove it
from the graph and find a minimum spanning tree of the remaining graph
using Kruskal or Prim's alrgorithm, denote the MST as T'.
3. If the total weight of T' is greater than the total weight of T, then edge e
is a critical edge. Otherwise, it's NOT a critical edge 
*/

/* -- python code (pseudo code):
	function find_critical_edges(graph):
		T = minimum_spanning_tree(graph)
		critical_edges = []
		for e in graph.edges:
			graph.remove_edge(e)
			T_prime = minimum_spanning_tree(graph)
			if T_prime.total_weight > T.total_weight:
				critical_edges.append(e)
			graph.add_edge(e) # restore the original graph
		return critical_edges
*/

#include <bit/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator <(const Edge& other) const {
        return weight < other.weight;
    }
};

//function to find the critical edges
vector<Edge> find_critical_edges(vector<Edge>& edges, int V) {
    vector<Edge> critical_edges;
    vector<Edge> mst_edges;

    // Find minimum spanning tree using Kruskal's algorithm
    sort(edges.begin(), edges.end());
    vector<vector<int> > adj(V);
    for (const Edge& e : edges) {
        adj[e.u].push_back(e.v);
        adj[e.v].push_back(e.u);
        mst_edges.push_back(e);
    }

    // Iterate through each edge and check if it's critical
    for (const Edge& e : edges) {
        vector<Edge> remaining_edges = edges;
        remaining_edges.erase(remove(remaining_edges.begin(), remaining_edges.end(), e), remaining_edges.end());

        // Find minimum spanning tree of the remaining graph
        vector<Edge> new_mst_edges;
        vector<vector<int>> new_adj(V);
        for (const Edge& new_e : remaining_edges) {
            new_adj[new_e.u].push_back(new_e.v);
            new_adj[new_e.v].push_back(new_e.u);
            new_mst_edges.push_back(new_e);
        }

        // Check if the total weight of the new MST is greater than the original MST
        int new_total_weight = 0;
        for (const Edge& new_e : new_mst_edges) {
            new_total_weight += new_e.weight;
        }
        int total_weight = 0;
        for (const Edge& e : mst_edges) {
            total_weight += e.weight;
        }
        if (new_total_weight > total_weight) {
            critical_edges.push_back(e);
        }
    }

    return critical_edges;
}

//check connectivity
bool is_connected(vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    dfs(adj, 0, visited);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

void dfs(vector<vector<int>>& adj, int u, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(adj, v, visited);
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<Edge> edges(E);
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    vector<Edge> critical_edges = find_critical_edges(edges, V);
    cout << "Critical edges:" << endl;
    for (const Edge& e : critical_edges) {
        cout << e.u << " " << e.v << " " << e.weight << endl;
    }

    return 0;
}