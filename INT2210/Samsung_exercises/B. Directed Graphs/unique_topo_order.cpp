#include <bits/stdc++.h>
using namespace std;
#define V 6 // số đỉnh

int graph[V][V] = {0}; // Initialise Adjaciency list
int Incoming_Degree[V] = {0}; // Incoming array

// find the incoming array
void Find_Incoming_Degree() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j]) Incoming_Degree[j]++;
        }
    }
}

// Kahn's algorithm (last question)
vector<int> Topo_Sort() {
    queue<int> q;
    vector<int> topological_order;

    for (int i = 0; i < V; i++) {
        if (Incoming_Degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topological_order.push_back(u);

        for (int i = 0; i < V; i++) {
            if (graph[u][i] == 1) {
                Incoming_Degree[i]--;
                if (Incoming_Degree[i] == 0) {
                    q.push(i);
                }
            }
        }
    }

    return topological_order;
}

// check if the graph has the unique topological sort
bool Is_Unique_Topo_Order(const vector<int>& topo_order) {
    for (size_t i = 0; i < topo_order.size() - 1; i++) {
        int u = topo_order[i];
        int v = topo_order[i + 1];
        if (graph[u][v] == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<pair<int, int> > edges = {
        {5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}
    };

    for (auto edge : edges) {
        int x = edge.first;
        int y = edge.second;
        graph[x][y] = 1;
    }
    Find_Incoming_Degree();
    vector<int> topo_order = Topo_Sort();

    if (topo_order.size() != V) {
        cout << "Graph has a cycle!" << endl;
    } else {
        if (Is_Unique_Topo_Order(topo_order)) {
            cout << "There is a unique topological sort." << endl;
        } else {
            cout << "the graph has many topological sort." << endl;
        }
    }

    return 0;
}
