//modified Dijkstra's Algorithm for longest path
/*
1. Initialise the distance to all vertices as '-INF', except for the source vertex,
which is set to '0'
2. Create a priority queue to store vertices to be processed, with the source
vertex as the first element
3. do something with the priority queue
4. After the algorithm terminates, the longest path from the source to each vertex
is stored in the distance array
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int maxn = 100001;

int v, e, src, des;
vector<pair<int, int> > adj[maxn]; //adjacency list <vertex, weight>
int parent[maxn];

void Input() {
	cin >> v >> e >> src >> des;
	for (int i = 0; i < e; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({y, w});
		adj[y].push_back({x, w}); //undirected graph
	}
}

void Longest_Path_Dijkstra(int src, int des) {
	vector<int> dis(v + 1, -INF);
	dis[src] = 0;
	parent[src] = src;
	priority_queue<pair<int, int> > Q; // standard max - priority queue
	//<type, container, compare>
	Q.push({0, src});
	while(!Q.empty()) {
		pair<int, int> top = Q.top();
		int u = top.second;
		int v = top.first;
		Q.pop();
		if (v < dis[u]) continue;
		
		for (auto it : adj[u]) {
			int v = it.first;
			int w = it.second;

			if (dis[v] < dis[u] + w) {
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
    while (t != src) {
        path.push_back(t);
        t = parent[t];
    }
    path.push_back(src); // add to vector as the starting vertex
    reverse(begin(path), end(path));
    
    for (int x : path) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    Input();
    Longest_Path_Dijkstra(src, des);
    return 0;
}