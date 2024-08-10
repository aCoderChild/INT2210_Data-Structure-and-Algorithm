/* -- Algorithm:
1. tạo một tập cạnh mới T = S
2. Xoá tất cả các cạnh S ra khỏi đồ thị G
3. Tìm MST sử dụng Kruskal hoặc Prim
3. Thêm cá cạnh T vào MST min vừa tìm được

--Pseudo code--:
Input: Graph G, edge set S
Output: MST of G that contains all edges in S

1. Create a new edge set T = S
2. Remove all edges in S from graph G
3. Find the MST of the remaining graph G using Kruskal's algorithm
4. Add all edges in T to the MST found in step 3
5. Return the resulting MST
*/

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

bool dfs(vector<vector<int> >& graph, int u, vector<bool>& visited, vector<int>& parent) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            parent[v] = u;
            if (dfs(graph, v, visited, parent)) {
                return true;
            }
        } else if (parent[u] != v) {
            return true;
        }
    }
    return false;
}

//check if it contains a cycles
bool has_cycle(vector<Edge>& edges, Edge& new_edge) {
    vector<vector<int> > graph(edges.size() + 1);
    for (const Edge& e : edges) {
        graph[e.u].push_back(e.v);
        graph[e.v].push_back(e.u);
    }
    graph[new_edge.u].push_back(new_edge.v);
    graph[new_edge.v].push_back(new_edge.u);

    vector<bool> visited(edges.size() + 1, false);
    vector<int> parent(edges.size() + 1, -1);

    for (int i = 0; i <= edges.size(); i++) {
        if (!visited[i]) {
            if (dfs(graph, i, visited, parent)) {
                return true;
            }
        }
    }
    return false;
}

vector<Edge> find_mst_with_edges(vector<Edge>& edges, vector<Edge>& S) {
    vector<Edge> T = S;
    vector<Edge> remaining_edges;
    for (const Edge& e : edges) {
        bool found = false;
        for (const Edge& s : S) {
            if (e.u == s.u && e.v == s.v && e.weight == s.weight) {
                found = true;
                break;
            }
        }
        if (!found) {
            remaining_edges.push_back(e);
        }
    }

    sort(remaining_edges.begin(), remaining_edges.end());

    vector<Edge> mst_edges;
    for (const Edge& e : remaining_edges) {
        if (!has_cycle(mst_edges, e)) {
            mst_edges.push_back(e);
        }
    }

    mst_edges.insert(mst_edges.end(), T.begin(), T.end());
    return mst_edges;
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<Edge> edges(E);
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    int S_size;
    cin >> S_size;
    vector<Edge> S(S_size);
    for (int i = 0; i < S_size; i++) {
        cin >> S[i].u >> S[i].v >> S[i].weight;
    }

    vector<Edge> mst_edges = find_mst_with_edges(edges, S);

    cout << "Minimum Spanning Tree Edges:" << endl;
    for (const Edge& e : mst_edges) {
        cout << e.u << " " << e.v << " " << e.weight << endl;
    }

    return 0;
}

//time complexity: O(E+V)
//if we use disjoint union set: O(E*logE)