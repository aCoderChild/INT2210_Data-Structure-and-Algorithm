#include <bits/stdc++.h>
using namespace std;

const int N = 2e5; //maximum number of NODES
#define INF numeric_limits<int>::max()
int n, m;
vector<int> edge[N];
bool visited[N];
int dfsIndex[N]; 
int minIndex[N]; //be updated to reflect the smallest 'dfsIndex' reachable from 'u'
int cur = 0; // a global variable that keeps track of the order in which nodes are visited

void DFS(int u, int pa) {
    cur += 1;
    dfsIndex[u] = minIndex[u] = cur; //is set to 'cur' to mark the order in which node u is FIRST visited
    visited[u] = true;
    for (int v : edge[u]) {
        if (!visited[v]) {
            DFS(v, u);
        }
        if (v != pa) {
            minIndex[u] = min(minIndex[u], minIndex[v]);
        }
    }
}

int main() {
    cin >> n >> m;

    // Kiểm tra số cạnh và số đỉnh
    if (m != n - 1) {
        cout << "NO" << endl;
        return 0;
    }

    // Khởi tạo các mảng
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
        minIndex[i] = INF;
    }

    int u, v;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    bool ans = true;
    DFS(1, -1);

    // Kiểm tra liên thông của đồ thị
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            ans = false;
            break;
        }
    }

    // Kiểm tra đồ thị có phải là cây không
    if (ans) {
        for (int u = 1; u <= n; u++) {
            for (int v : edge[u]) {
                if (dfsIndex[u] < minIndex[v]) {
                    ans = false;
                    break;
                }
            }
            if (!ans) break;
        }
    }

    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
