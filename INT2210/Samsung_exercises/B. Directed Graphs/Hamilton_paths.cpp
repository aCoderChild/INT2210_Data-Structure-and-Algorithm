//Kahn's algortihm  - for topological sorting 
//Only certain types of graph have a topological orderings. These are
//Directed Acyclic Graph: is a finite directed graph with no directed cycles
//topological ordering s are NOT unique 

//topological sort
#include <bits/stdc++.h>
using namespace std;
#define V 6 //number of vertex

int graph[V][V] = {0};
int Incoming_Degree[V] = {0};

//find the order
void Find_Topological_Ordering() {
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (graph[i][j]) Incoming_Degree[j]++;
		}
	}
}

void Topo_Sort() {
	queue<int> q;
	vector<int> topological_order;

	for (int i = 0; i < V; i++) {
		if(Incoming_Degree[i] == 0) {
			q.push(i);
		}
	}

	while(!q.empty()) {
		int u = q.front();
		q.pop();
		topological_order.push_back(u);
		for (int i = 0; i < V; i++) {
			if(graph[u][i] == 1) Incoming_Degree[i]--;
			if (Incoming_Degree[i] == 0) q.push(i);
		}
	}

	//check if there is a cycle
	if (topological_order.size() != V) {
		cout << "Graph has a cycle. Topological sorting not Possible" << endl;
	} else {
		cout << "Topological order: ";
		for (int i : topological_order) {
			cout << i << " ";
		}
		cout << endl;
	}
}

//for testing only
int main() {
    // Example graph edges input (you can modify this as needed)
    //vector<pair<int, int> > edges = {
    //    {5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}
    //};

    edges.push_back({5, 2});
    edges.push_back({5, 0});
    edges.push_back({4, 0});
    edges.push_back({4, 1});
    edges.push_back({2, 3});
    edges.push_back({3, 1});

    // Build the adjacency matrix
    for (auto edge : edges) {
        int x = edge.first;
        int y = edge.second;
        graph[x][y] = 1;
    }

    // Find the incoming degree of each vertex
    Find_Topological_Ordering();

    // Perform topological sorting
    Topo_Sort();

    return 0;
}