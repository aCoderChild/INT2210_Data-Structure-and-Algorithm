#include <bits/stdc++.h>
using namespace std;
#define V 10 // change to the number of vertices in the largest graph
#define E 15 // change to the number of edges in the largest graph

map<int, vector<int>> adj;
map<int, int> degree;

void DFS(int curr, vector<bool>& visited) {
    visited[curr] = true;
    for (auto i : adj[curr]) {
        if (!visited[i]) {
            DFS(i, visited);
        }
    }
}

bool Connected_Graph() {
    vector<bool> visited(V, false);
    int node = -1;
    
    // Finding starting node for DFS
    for (int i = 0; i < V; i++) {
        if(!adj[i].empty()) {
            node = i;
            break;
        }
    }

    if (node == -1) return true;
    DFS(node, visited);
    for (int i = 0; i < V; i++) {
        if(visited[i] == false && adj[i].size() > 0) return false; // multi-component
    }
    return true;
}

// Function to check if the vertex can be added into the Hamiltonian cycle
bool isSafe(int v, vector<int>& path, int pos) {
    if (find(adj[path[pos - 1]].begin(), adj[path[pos - 1]].end(), v) == adj[path[pos - 1]].end()) // if v is NOT found in the array
        return false;

    // if the vertex has already been added in the Hamiltonian cycle
    if (find(path.begin(), path.end(), v) != path.end())
        return false;

    return true;
}

// A recursive utility function to solve the Hamiltonian cycle problem
bool Hamilton_Cycle_Utility(vector<int>& path, int pos) {
    // base case: if all the vertices have been included in the path
    if (pos == V) {
        // there is an edge from the last included vertex to the first vertex
        if (find(adj[path[pos-1]].begin(), adj[path[pos-1]].end(), path[0]) != adj[path[pos-1]].end())
            return true;
        return false;
    }

    // try different vertices as a next candidate in Hamiltonian Cycle
    // we don't try 0 as we included 0 as starting point in hamCycle
    // BACKTRACKING STEP
    for (int v = 0; v < V; v++) {
        if (isSafe(v, path, pos)) {
            path[pos] = v;
            // recur to construct the rest of the path
            if (Hamilton_Cycle_Utility(path, pos+1) == true)
                return true;

            path[pos] = -1;
        }
    }
    return false;
}

bool has_Hamilton_cycle() {
    bool flag = false;
    vector<int> path(V, -1); // initialize the path full of -1

    for (int start = 0; start < V; start++) {
        path[0] = start; // try each vertex as starting point
        //must assgign the starting point path[0] before calling Hamiltonian cycle
        if (Hamilton_Cycle_Utility(path, 1) == true) {
            flag = true;
            cout << "Hamiltonian cycle exists starting from vertex " << start << ": ";
            for (int j = 0; j < V; j++) {
                cout << path[j] << " ";
            }
            cout << path[0] << endl; // to complete the cycle
            return true; // if you want to find only one Hamiltonian cycle, break here
        }
    }

    if (flag == false) cout << "No Hamiltonian cycle exists!" << endl;
    return flag;
}

bool has_Eulerian_cycle() {
    // Check if all non-zero degree vertices are connected
    if (!Connected_Graph()) return false;

    // Check if all vertices with non-zero degree have even degree
    for (int i = 0; i < V; i++) {
        if (adj[i].size() % 2 != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << "Enter the Graph (input edges in the format x y): " << endl;
    for (int i = 0; i < E; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        degree[x]++;
        degree[y]++;
    }

    cout << "Is the graph connected: " << (Connected_Graph() ? "Yes" : "No") << endl;

    if (has_Eulerian_cycle()) {
        cout << "Eulerian cycle exists!" << endl;
    } else {
        cout << "No Eulerian cycle exists!" << endl;
    }

    has_Hamilton_cycle();

    return 0;
}
