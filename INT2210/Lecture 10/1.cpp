//connected components
//-- Chat GPT ---
#include <iostream>
#include <vector>
#define c 10000

using namespace std;
vector<int> adj[c]; // adjacency list: store the edges
bool visited[c] = {false}; // visited array: store the nodes

void dfs(int node) {
    visited[node] = true;
    for (int child : adj[node]) {
        if (!visited[child]) {
            dfs(child);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x); // for undirected graph
    }

    int connectedComponents = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            connectedComponents++;
        }
    }

    cout << connectedComponents << endl;

    return 0;
}

/* pseudo code --
n = number of nodes in the graph
g = adjacency list representing graph
count = 0
components = empty integer array
visited = false, ... false

function findComponents():
    for (i = 0; i < n; i++):
        if !visited[i]:
            count++:
            dfs(i)
        return (count, components)

function dfs(at):
    visited[at] = true
    components[at] = count
    for (next : g[at]):
        if !visited[next]:
            dfs(next)
*/

//most General: 2 maps for adjacient table (2D) and visited array



