//-- CHAT GPT --
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[100005]; // adjacency list
int dist[100005]; // distance array

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int child : adj[node]) {
            if (dist[child] == -1) {
                dist[child] = dist[node] + 1;
                q.push(child);
            }
        }
    }
}

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    fill(dist, dist + n + 1, -1); // initialize distance array with -1

    bfs(X);

    cout << dist[Y] << endl;

    return 0;
}