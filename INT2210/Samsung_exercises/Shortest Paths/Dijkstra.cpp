// Achtung: all the weights must be >= 0 
// Time complexity = O((E+V)*logE)
// Use priority Queue (min Priority Queue)

/*
1. set the distance to the source to 0 and the distance to the remaining vertices
to infinity
2. set the current vertex to the source
3. flag the current vertex as Visited
4. for all the vertices adjacent to the current vertex:
	if the current vertex is u
	adjacent to u is v
	d[u] = 50 (ex)
	d[v] = 120
	=> d[v] = min(d[v], d[u] + (u,v))
5. from the set of unvisited vertices
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 100001;
const int INF = 1e9; // INF represents infinity (a large number)

int v, e, cur, des;
vector<pair<int, int> > adj[maxn]; // Adjacency list to store edges with weights
int parent[maxn]; // Array to store the parent of each vertex in the shortest path

void Input() {
    cin >> v >> e >> cur >> des;
    for (int i = 0; i < e; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
    }
}

void Dijkstra(int cur, int des) {
    vector<ll> dis(v + 1, INF); // Distance array initialized to INF
    dis[cur] = 0;
    parent[cur] = cur;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q; // Min-priority queue
    //pair: key - distance, value - vertex corresponding
    Q.push({0, cur}); // Push the source with distance 0

    while (!Q.empty()) {
        pair<int, int> top = Q.top();
        int u = top.second;
        int d = top.first;
        Q.pop();

        if (d > dis[u]) continue; // If the current distance is greater than the recorded distance, skip it
        //dis[u]: the distance that has been updated before
        
        // Relaxation step
        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                Q.push({dis[v], v});
                parent[v] = u;
            }
        }
    }

    // Output the shortest distance from cur to des
    cout << dis[des] << endl;

    // Reconstruct and print the path from cur to des
    vector<int> path;
    int t = des;
    while (t != cur) {
        path.push_back(t);
        t = parent[t];
    }
    path.push_back(cur); // add to vector as the starting vertex
    reverse(begin(path), end(path));
    
    for (int x : path) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    Input();
    Dijkstra(cur, des);
    return 0;
}

