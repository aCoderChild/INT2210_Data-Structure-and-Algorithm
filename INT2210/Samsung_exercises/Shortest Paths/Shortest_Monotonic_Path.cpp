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

void Shortest_Monotonic_Path(int src, int des) {
	vector<int> dis(v + 1, INF);
	dis[src] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;
	Q.push({0, src});

	while(!Q.empty()) {
		pair<int, int> top = Q.top();
		int v = top.first;
		int u = top.second;
		Q.pop();

		for (auto it : adj[u]) {
			int v = it.first;
			int w = it.second;

			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				Q.push({dis[v], v});
			}
		}
	}

	cout << "Shortest Monotonic Path from " << src << " to " << des << ": " << dis[des] << endl;
}

int main()
{
	Input();
	Shortest_Monotonic_Path(src, des);
}