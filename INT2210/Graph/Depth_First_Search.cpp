// depth first tranversal
// depth first: STACK FILO

/*-- Pseudocode --
-- Recursive = stack --
-- Code by Recursion --
DFS(u) {
	<Tham Dinh u>:
	visitied[u] = true // danh dau u dc tham
	for(v : adj[u]) {
		if(!visited[v])
			DFS(v)
	}
}
*/

#include<bits/stdc++.h>
using namespace std;
#define c 10000

int n, m;
vector<int> adj[c];
bool visited[c];

void Input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
} 

void DFS(int u) {
	cout << u << " ";
	visited[u] = true;
	for (int v : adj[u]) {
		if (!visited[v]) {
			DFS(v);
		}
	}
}

int main()
{
	Input();
	DFS(1);
}

