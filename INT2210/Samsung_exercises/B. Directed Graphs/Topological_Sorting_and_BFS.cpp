//topological sorting for Directed Acyclic Graph (DAG)
//is a linear ordering of vertices such that for every directed edge u-v,
//vertex u comes before v in the ordering

/*--Algorithm--
1. Bắt đầu với một danh sách topo trống
2. TÌm đỉnh nguồn của DAG. thêm vào cuối danh sách topo
3. Loại bỏ đỉnh này và tất cả cạnh kề ra khỏi DAG
Nếu số đỉnh của DAG lớn hơn 0, quay lại bước 2

*/

//acyclic: the graph which has no circuits

#include <bits/stdc++.h>
using namespace std;

const int maxN = 110;

int n, m;
//n: số đỉnh
//m: số cạnh
int indegree[maxN], ans[maxN];
vector<int> g[maxN], topo;
queue<int> listSource;

int main()
{
	cin >> n >> m;
	while (m--) {
		int u, v; //u, v:một cũng nối từ u đến v trong đồ thị G
		cin >> u >> v;
		g[u].push_back(v);
		indegree[v]++;
	}

	for (int u = 1; u <= n; u++) {
		if (!indegree[u]) listSource.push(u);
		//NO BREAK after finding the vertex
	}

	while(!listSource.empty()) {
		int u = listSource.front();
		listSource.pop();
		topo.push_back(u);
		for (auto v : g[u]) {
			indegree[v]--;
			if(!indegree[v]) listSource.push(v);
		}
	}

	if(topo.size() < n) {
		cout << "Error: graph contains a cycle";
		return 0;
	}

	int cnt = 0;
	for (auto x : topo) ans[x] = cnt++;
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	return 0;
}