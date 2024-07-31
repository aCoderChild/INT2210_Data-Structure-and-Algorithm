//goal: to prove a Bipartite
//code: check if a graph is bipartite or NOT

//USE BREADTH_FIRST_SEARCH (BFS)
/*--Algorithm to check if a graph is Bipartite--:
_ One approach: check whether the graph is 2 - colorable or NOT using backtracking algorithm m coloring problem
_ Simple algorithm to find out whether a given graph is Biparte or Not using BFS:
	1. Assign RED color to the source vertex
	2. color all the neighbors with BLUE color
	3. Color all neighbor's neighbors with RED
	4. Assign color to all vertices such that it satisfies all the constraints of m way cooring problem where m = 2
	5. while assigning colors, if we find a neighbor which is colored with the same color as current vertex, then the graph is NOT BIPARTITE
*/

#include <bits/stdc++.h>
using namespace std;
#define V 4 //number of vertices

using namespace std;

bool isBipartite (int G[][V], int src) {
	// create a color array to store colors
	// assigned to all vertices. Vertex num is used as index in this array
	// The value '-1' of colorArr[i] is used to indicate that NO COLOR is assigned to vertex 'i'
	// the value 1 is used to indicate first color is assigned 
	// the value 0 is used to indicated SECOND color

	int colorArr[V] = {-1};

	//assigned the first color to the first vertex
	colorArr[src] = 1;

	//Create a queue
	//for BFS tranversal
	queue<int> q;
	q.push(src);

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		//return false if there is a self_loop
		if (G[u][u] == 1) {
			return false;
		}

		for (int v = 0; v < V; v++) {
			if (G[u][v] && colorArr[v] == -1) {
				colorArr[v] = 1 - colorArr[u];
				q.push(v);
			}

			else if (G[u][v] && colorArr[v] == colorArr[u]) {
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int G[][V] = {{0, 1, 0, 1},
					{1, 0, 1, 0},
					{0, 1, 0, 1},
					{1, 0, 1, 0}};
	isBipartite(G, 0) ? cout << "YES" : cout << "NO" << endl;
	return 0;
}

/*
Giải thích tại sao đồ thị lưỡng cực khi và chỉ khi không có chu trình độ dài lẻ:
Phần 1: nếu là đồ thị lưỡng cực thì không chứa chu trình độ dài lẻ
- Giả sử G là một đồ thị lưỡng cực
=> có thể chia tập đỉnh V của G thành 2 tập rời U và W sao cho mỗi cạnh của G đều
nối một đỉnh trong U và một đỉnh trong V
- Giả sử rằng G có có chu trình độ dài lẻ. => số đỉnh là 2k+1 với k = 1, 2, 3...
Khi đi qua chu trình này sẽ phải xen kẽ giữa 2 tập U và W. Nhưng nếu chu trình có độ dài lẻ,
thì cuối cùng sẽ phải trở lại tập ban đầu, tức là có cạnh nối 2 đỉnh thuộc cùng 1 tập (đỉnh cuối và đỉnh đầu tiên)
=> Mâu thuẫn

Phần 2: nếu là đồ thị có chu trình lẻ thì không phải là đồ thị lưỡng cực
- Giả sử G là đồ thị có chu trình có độ dài lẻ. ta cần chứng minh G không là đồ thị lưỡng cực
- sử dụng code để check đồ thị lưỡng cực (:)))
*/