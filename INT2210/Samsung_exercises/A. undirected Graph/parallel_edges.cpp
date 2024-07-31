/*
A graph that has no paralell edges means a SIMPLE GRAPH, where
each pair of vertices can only be connected by one edge and there 
is no edges connect one vertex to itself
*/

//goal to construct a linear algorithm for counting the number of parallel
#include <bits/stdc++.h>
using namespace std;

# define V 6 //number of vertices
# define E 5 //number of edges

int table[V][V] = {0};

int Count_Parallels() {
	int count = 0;
	for (int i = 0; i < V; i++) {
		for (int j = i+1; j < V; j++) { //just consider the upper triangular of the matrix
			if (table[i][j] > 1) {
				count += table[i][j] - 1; //the number of parallel edges = total number of edges connect the vertices - 1
			}
		}
	}
	return count;

int main()
{
	cout << "Enter the graph (in the format of x and y: " << endl;
	for (int i = 0; i < E; i++) {
		int x, y;
		cin >> x >> y;
		table[x][y]++;
		table[y][x]++;
	}
	cout << "Number of parllel edges: " << Count_Parallels() << endl;
}