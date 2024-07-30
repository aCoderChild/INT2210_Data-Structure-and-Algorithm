/* --find Bridges in a graph using Tarjan's algorithm
Before learning the approach: understand which edge is termed as bridge. Suppose there
exists an edge from u->v, now after removal of this edge if v can't be reached by any 
other edges then u->v is BRIDGE

--ALGORITHM--:
- visited[] = to keep track of the visited vertices to implement DFS
- disc[] = to keep track when for the FIRST time that particular vertex is reached
- low[] = to keep track of the lowest possible time by which we can reach that vertex
'other than parent' so that if edge from parent is removed can the particular node 
can be reached other than parent

We will tranverse the graph using DFS traversal but with slight modifications while
traversing we will keep track of the parent node by which the particular node is reached
because we will update the low[node] = min(low[all it's adjacient node except parnet])
=> keep track of the parent

While traversing adjacient nodes let v of a particular node let u, then 3 cases arise:
1. v is the parent of u => skip the iteration
2. v is visited: update the low of update
3. v is not visited => check if (low[v] > disc[u])
*/

#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V; // number of vertices
    list<int>* adj; // adjacency list
    void bridgeUtil(int u, vector<bool>& visited, vector<int>& disc, vector<int>& low, int parent);
  
public:
    Graph(int V);
    void addEdge(int x, int y);
    bool has_Bridge(); // check if the graph has a bridge
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int x, int y) {
    adj[x].push_back(y);
    adj[y].push_back(x); // undirected graph
}

// A recursive function that finds and prints bridges using DFS traversal
// disc: discovery time of each vertex
// low: array that holds the LOWEST discovery time
void Graph::bridgeUtil(int u, vector<bool>& visited, vector<int>& disc, vector<int>& low, int parent) {
    static int time = 0; // act as a timer (by step)
    visited[u] = true;
    disc[u] = low[u] = time++;
    
    for (auto v : adj[u]) {
        // If v is the parent
        if (v == parent) {
            continue;
        }
        
        // If v is visited
        if (visited[v]) {
            low[u] = min(low[u], disc[v]);
        }
        // If v is not visited
        else {
            bridgeUtil(v, visited, disc, low, u);
            low[u] = min(low[u], low[v]);
            
            if (low[v] > disc[u]) {
                cout << "Bridge found: " << u << " - " << v << endl;
            }
        }
    }
}

bool Graph::has_Bridge() {
    vector<bool> visited(V, false);
    vector<int> disc(V, -1);
    vector<int> low(V, -1);

    // Call the bridgeUtil for every vertex
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            bridgeUtil(i, visited, disc, low, -1);
        }
    }
    
    return true; // This can be changed based on your condition
}

int main() {
    // Create graph
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);

    cout << "Finding bridges in the graph:" << endl;
    g1.has_Bridge();
    
    return 0;
}
