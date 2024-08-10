//Prim's minimum spanning tree algorithm
//lazy version

/*
given an undirected graph with WEIGHTED edges, a MINIMUM spanning tree (MST)
is a subset of the edges in the graph which connects all vertices together
(without creating any cycles) while minimizing the total edge cost

Prim's MST Algorithm"
- a greedy MST algorithm that works well on dense graphs
- the lazy version of Prim's has a runtime of O(E * log(E)), but the eager 
version has a better runtime O(E * log(V)).

Lazy Prim's MST Overview:
1. Maintian a min Priority Queue (PQ) that sorts edges based on min edge cost. 
This will be used to dtermine the NEXT node to visit and the edge used to get there
2. start the algorithm. mark s as visited and iterate over all edges of s,
adding them to the PQ.
3. while !PQ.empty() and a MST has NOT been formed, DEQUEUE the next cheapest
edge from the PQ. 
if the dequeued edge is oudated (meaning the node it points to has already been
visited) then skip it and poll again. 
otherwise, mark the current node as visited and add the selected edge to the MST
*/

/*
Eager Prim's Algorithm:
1. Maintain a min indexed priority queue of size V that sorts vertex-edge pairs
(v, e) based on the min edge cost of e. By default, all vertices v have a 
best value of (v, 0) in the queue
2. start the algorithm on any node 's'. Mark s as visited and relax all edges of s
3. while the queue is not empty and a MST has not been formed, dequeue the 
next best (v, e) pair from the queue. Mark node v as visited and add edge e to
the MST
4. relax all edges of v while making sure not to relax any edge pointing to
a node which has already been visited

//relaxing: updating the entry for node v in the queue from (v, e_old) to (v, e_new)
if the new edge e_new from u->v has a lower cost than e_old 
*/

//similar to eager prim
#include<bits/stdc++.h>
using namespace std;

#define V 6		//No of vertices
#define INT_MAX 999999

int selectMinVertex(vector<int>& value,vector<bool>& setMST)
{
	int minimum = INT_MAX;
	int vertex;
	for(int i=0;i<V;++i)
	{
		if(setMST[i]==false && value[i]<minimum)
		{
			vertex = i;
			minimum = value[i];
		}
	}
	return vertex;
}

void findMST(int graph[V][V])
{
	int parent[V];		//Stores MST
	vector<int> value(V,INT_MAX);	//Used for edge relaxation
	vector<bool> setMST(V,false);	//TRUE->Vertex is included in MST

	//Assuming start point as Node-0
	parent[0] = -1;	//Start node has no parent
	value[0] = 0;	//start node has value=0 to get picked 1st

	//Form MST with (V-1) edges
	for(int i=0;i<V-1;++i)
	{
		//Select best Vertex by applying greedy method
		int U = selectMinVertex(value,setMST);
		setMST[U] = true;	//Include new Vertex in MST

		//Relax adjacent vertices (not yet included in MST)
		for(int j=0;j<V;++j)
		{
			/* 3 constraints to relax:-
			      1.Edge is present from U to j.
			      2.Vertex j is not included in MST
			      3.Edge weight is smaller than current edge weight
			*/
			if(graph[U][j]!=0 && setMST[j]==false && graph[U][j]<value[j])
			{
				value[j] = graph[U][j];
				parent[j] = U;
			}
		}
	}
	//Print MST
	for(int i=1;i<V;++i)
		cout<<"U->V: "<<parent[i]<<"->"<<i<<"  wt = "<<graph[parent[i]][i]<<"\n";
}

int main()
{
	int graph[V][V] = { {0, 4, 6, 0, 0, 0},
						{4, 0, 6, 3, 4, 0},
						{6, 6, 0, 1, 8, 0},
						{0, 3, 1, 0, 2, 3},
						{0, 4, 8, 2, 0, 7},
						{0, 0, 0, 3, 7, 0} };

	findMST(graph);	
	return 0;
}

//TIME COMPLEXITY: O(V^2)