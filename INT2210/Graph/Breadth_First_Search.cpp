// BFS is particularly USEFUl for Finding the shortest path on unweighted graphs
// Use a QUEUE
#include <bits/stdc++.h>
using namespace std;
#define c 10000

int n, m;
//n: vertices
//m: edges

vector<int> adj[c]; //array to store the adjacient list
bool visited[c];

void Input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited, false, sizeof(visited)); //use memset
}

void BFS(int u) {
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		cout << v << " "; //cout this because it's a QUEUE FIFO
		for (int x : adj[v]) {
			if (!visited[x]) {
				q.push(x);
				visited[x] = true;
			}
		}
	}
}

int main()
{
	Input();
	BFS(1);
}
