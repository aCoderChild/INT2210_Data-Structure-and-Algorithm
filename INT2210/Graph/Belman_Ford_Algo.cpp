#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<vector<int>> floydWarshall(vector<vector<vector<int>>>& graph) {
    int n = graph.size();
    vector<vector<int>> distance(n, vector<int>(n, numeric_limits<int>::max()));

    for (int i = 0; i < n; i++) {
        distance[i][i] = 0;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (distance[i][k] != numeric_limits<int>::max() &&
                    distance[k][j] != numeric_limits<int>::max() &&
                    distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    return distance;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<vector<int>>> graph(n, vector<vector<int>>(n, vector<int>(0)));

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v].push_back(w);
    }

    vector<vector<int>> distance = floydWarshall(graph);

    cout << "Shortest distances:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (distance[i][j] == numeric_limits<int>::max()) {
                cout << "INF ";
            } else {
                cout << distance[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}