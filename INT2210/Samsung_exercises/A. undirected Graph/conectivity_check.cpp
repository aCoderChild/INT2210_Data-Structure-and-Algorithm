#include <bits/stdc++.h>
using namespace std;
#define V 6 //define the number of vertices (starting from 0)
#define E 5 // define the number of edges

map<int, vector<int> > adj; // initialise the adjaciency list
void DFS(int curr, vector<bool>& visited) {
	visited[curr] = true;
	for (auto i : adj[curr]) {
		if (visited[i] == false) { //just to check if i is visited or not
			visited[i] = true;
			DFS(i, visited);
		}
	}
}

bool Connected_Graph() {
	vector<bool> visited(V, false);
	int node = -1;
	for (int i = 0; i < V; i++) {
		if(adj[i].size() > 0) { //beacuse this time all elements is FALSE, not TRUE
			node = i;
			break;
		}
	}
	if (node == -1) return true;

	DFS(node, visited);
	for (int i = 0; i < V; i++) {
		if (visited[i] == false && adj[i].size() > 0) {
			return false;
		}
	}
	return true;
}

int main()
{
	cout << "Enter the graph (in the form of x and y: " << endl;
	for (int i = 0; i < E; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	cout << "Is the graph connected: " << (Connected_Graph() ? "YES" : "NO") << endl;
	return 0;
}