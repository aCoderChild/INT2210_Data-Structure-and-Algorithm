/*-- Algorithm step --
1. connectivity check
	do dfs and mark nodes in conponent
	check if any node with degreee > 0 was unvisited

2. count odd degree nodes (use adjaciency list)
	count = 0 => eulerian graph
	count = 2 => semi eulerian graph
	count > 2 => not eulerian graph
*/

#include <bits/stdc++.h>
using namespace std;

#define V 10
#define E 10

map<int, vector<int> > adj;

void DFS(int curr, vector<bool>& visited)
{
	visited[curr] = true;
	for (auto i : adj[curr])
	{
		if (!visited[i]) {
			DFS(i, visited);
		}
	}
}

bool Connected_Graph() 
{
	vector<bool> visited(V, false);
	int node = -1; // node to start DFS
	for (int i = 0; i < V; i++) {
		if (adj[i].size() > 0) {
			node = i;
			break;
		}
	}
	if (node == -1) {
		return true; // no start node was found
		//=> no edges are present in graph
	}

	DFS(node, visited); //CHECK STEP
	//check if all the non-zero vertices are VISITED
	for (int i = 0; i < V; i++) {
		if (visited[i] == false && adj[i].size() > 0) {
			//if adj[i].size() == 0 => NO MATTER, still a sungle component
			return false; //multi - component
		}
	}
	return true;
}

int find_Euler()
{
	if (!Connected_Graph()) { // check if the graph is CONNECTED
		return 0; // NOT an Eulerian graph
	}

	int odd = 0; // how many nodes have odd degrees
	for (int i = 0; i < V; i++) {
		if (adj[i].size() & 1) {
			odd += 1;
		}
	}

	if (odd > 2) {
		return 0; // graph is NOT an Eulerian graph
	} //only start and end node can have odd degree

	return (odd == 0) ? 2 : 1;
}	

void findEuler_Path_Cycle()
{
	int count = find_Euler();
	if (count == 0) {
		cout << "Graph if not an Eulerian graph" << endl;
	}
	else if (count == 2) {
		cout << "Graph has an Euler circuit" << endl;
	}
	else {
		cout << "Graph has Euler path" << endl;
	}
}


int main()
{
	cout << "Enter the graph: " << endl;
	for (int i = 0; i < E; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	findEuler_Path_Cycle();

	return 0;
}

//TIME COMPLEXITY: O(V+E)
/* -- Functions:
1. DFS
2. Check connectivity
3. count odd degrees
4. summarise => conclusion
*/