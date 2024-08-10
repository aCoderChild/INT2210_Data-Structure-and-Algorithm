// Targjan algorithm
// Strongly connected components

/*
DFS spanning forest: when DFS traverse a directed graph, it defines a set of non-intersecting 
tree=>spannning forest of DFS
classify the edges of the graph depending on how dfs dicovers them.
If DFS processes verrtex v it discovers:
	- an unvisited neighbour u, then edge(v, u) is a tree edge
	- a visited but not yet fully processed neightbour w, then edge (v w) is a back edge
	- a fullt processed neighbour t, then edge (v, t) is a cross edge
*/
#include <bits/stdc++.h>
using namespace std;

#define V 6 //the number of vertex
int graph[V][V];

void findComponent(int u, int disc[], int low[], stack<int>& stk, bool visited[]) {
	static int time = 0;
	disc[u] = low[u] = time++;
	stk.push(u);
	visited[u] = true;

	for (int v = 0; v < V; v++) {
		if (graph[u][v]) {
			if (disc[v] == -1) { //if not visited
				findComponent(v, disc, low, stk, visited); //DFS traversal
				low[u] = min(low[u], low[v]);
			}
			else if(visited[v]) {
				low[u] = min(low[u], disc[v]);
			}
		}
	}

	int poppedItem = 0;
	if(low[u] == disc[u]) {
		while(stk.top() != u) {
			poppedItem = stk.top();
			cout << poppedItem << " ";
			visited[poppedItem] = false;
			stk.pop();
		}
		poppedItem = stk.top();
    	cout << poppedItem << endl;
    	visited[poppedItem] = false;
    	stk.pop();
	}
}

void stronglyConnectedGraph() {
	int disc[V];
	int low[V];
	bool visited[V];
	stack<int> stk;

	for (int i = 0; i < V; i++) {
		disc[i] = -1;
		low[i] = -1;
		visited[i] = false;
	}

	for (int i = 0; i < V; i++) {
		if(disc[i] == -1) {
			findComponent(i, disc, low, stk, visited);
		}
	} 
}

int main()
{
	// Example graph
    // Initialize the adjacency matrix with zeros
    memset(graph, 0, sizeof(graph));

    // Add edges to the graph
    graph[0][1] = 1;
    graph[1][2] = 1;
    graph[2][0] = 1;
    graph[1][3] = 1;
    graph[3][4] = 1;
    graph[4][5] = 1;
    graph[5][3] = 1;

    cout << "Strongly Connected Components in the graph:" << endl;
    stronglyConnectedGraph();

    return 0;
}