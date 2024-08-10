#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

// edge struct
struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

// So sánh và tìm cạnh có trọng số lớn nhất
Edge Compare_Edges(vector<Edge> e) {
    Edge maximum = e[0];
    for (const auto& i : e) {
        if (i.weight > maximum.weight) {
            maximum = i;
        }
    }
    return maximum;
}

// Tìm tập hợp của đỉnh v
int findSet(int v, vector<int>& parent) {
    if (v == parent[v])
        return v;
    return parent[v] = findSet(parent[v], parent);
}

// Hợp nhất hai tập hợp
void unionSets(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = findSet(a, parent);
    b = findSet(b, parent);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

// Kiểm tra đồ thị có chu trình sử dụng DFS
bool isCyclicUtil(int v, vector<int>& parent, vector<int>& rank, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& parentEdge) {
    if (visited[v])
        return true;

    visited[v] = true;
    for (int u : adj[v]) {
        if (parentEdge[u] != v) {
            parentEdge[u] = v;
            if (isCyclicUtil(u, parent, rank, adj, visited, parentEdge))
                return true;
        }
    }
    visited[v] = false;
    return false;
}

// Hàm kiểm tra đồ thị có chu trình
bool isCyclic(vector<Edge>& mst, int V) {
    vector<int> parent(V);
    vector<int> rank(V, 0);
    for (int i = 0; i < V; i++)
        parent[i] = i;

    vector<vector<int>> adj(V);
    for (auto& edge : mst) {
        int u = edge.u;
        int v = edge.v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(V, false);
    vector<int> parentEdge(V, -1);

    for (int i = 0; i < V; i++) {
        if (!visited[i] && isCyclicUtil(i, parent, rank, adj, visited, parentEdge))
            return true;
    }

    return false;
}

// Thuật toán Vysotsky để tìm cây bao trùm nhỏ nhất
vector<Edge> vysotskyMST(vector<Edge>& edges, int V) {
    vector<Edge> mst;
    vector<int> parent(V), rank(V, 0);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.weight < b.weight; });

    for (Edge& edge : edges) {
        int u = findSet(edge.u, parent);
        int v = findSet(edge.v, parent);

        if (u != v) {
            unionSets(u, v, parent, rank);
            mst.push_back(edge);

            if (isCyclic(mst, V)) {
                Edge maxEdge = Compare_Edges(mst);
                mst.erase(remove(mst.begin(), mst.end(), maxEdge), mst.end());
            }
        }
    }

    return mst;
}

int main() {
    int V = 6; // Số đỉnh
    vector<Edge> edges;

    // Thêm các cạnh vào đồ thị
    edges.push_back(Edge(0, 1, 10));
    edges.push_back(Edge(0, 2, 6));
    edges.push_back(Edge(0, 3, 5));
    edges.push_back(Edge(1, 3, 15));
    edges.push_back(Edge(2, 3, 4));

    vector<Edge> mst = vysotskyMST(edges, V);

    cout << "Cây bao trùm nhỏ nhất (MST) bao gồm các cạnh:\n";
    for (Edge& edge : mst) {
        cout << edge.u << " - " << edge.v << " với trọng số " << edge.weight << endl;
    }

    return 0;
}
