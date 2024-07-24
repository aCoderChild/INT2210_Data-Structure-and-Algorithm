/* -- pseudocode --
ConnectedComponent() {
	cnt = 0
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			++cnt;
			dfs(i)
		}
	}
}
*/

#include <bits/stdc++.h>
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
	visited[u] = true; //set the node to TRUE - remember this step
	cout << u << " "; //cout HERE
	for (int i : adj[u]) {
		if (!visited[i]) {
			DFS(i);
		}
	}
}

void BFS(int u) {
	queue<int> q;
	q.push(u); //push and POP
	visited[u] = true;
	while(!q.empty()) {
		int v = q.front();
		cout << v << " "; //cout is THIS STEP
		q.pop();
		for (int i : adj[v]) {
			if (!visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

//Achtung!
void Connected_Components() {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			ans++;
			cout << endl;
			BFS(i);
		}
	}
	cout << endl;
	cout << ans;
}

int main()
{
	Input();
	Connected_Components();
}