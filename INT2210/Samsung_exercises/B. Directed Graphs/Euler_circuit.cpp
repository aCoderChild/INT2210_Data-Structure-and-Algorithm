//using Breadth First Search
/*
#include <bits/stdc++.h>
using namespace std;

#define maxN 1001

void BFS(int adj[][maxN], int n, int start, bool visited[]) { //start: start vertex
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int i = q.front();
        q.pop();
        for (int j = 0; j < n; j++) {
            if (adj[i][j] != 0 && !visited[j]) {
                visited[j] = true;
                q.push(j);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int countGoIn[n];
    int countGoOut[n];

    int adj[maxN][maxN] = {};
    int i, j;
    while (cin >> i >> j) {
        adj[i][j] = 1;
        countGoIn[j]++;
        countGoOut[i]++;
    }

    bool visited[n];
    BFS(adj, n, 0, visited);

    bool allVisited = true;
    for (int i = 0; i < n; i++) {
        if (countGoOut[i] > 0 && !visited[i]) {
            allVisited = false;
            break;
        }
    }

    bool haveEulerCycle = allVisited;
    if (allVisited) {
        for (int i = 0; i < n; i++) {
            if (countGoIn[i] != countGoOut[i]) {
                haveEulerCycle = false;
                break;
            }
        }
    }

    if (haveEulerCycle)
        cout << "Have Euler Cycle" << endl;
    else
        cout << "Not have Euler Cycle" << endl;

    return 0;
}
*/

//using DFS
#include <bits/stdc++.h>
using namespace std;
#define maxN 1001

bool visited[maxN];
void DFS(int adj[][maxN], int n, int v) {
	visited[v] = true;
	for (int i = 0; i < n; i++) {
		if(adj[v][i] != 0 && !visited[i]) { //n: the number of vertices
			DFS(adj, n, i);
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	int countGoIn[n];
	int countGoOut[n];

	int adj[maxN][maxN];
	int i, j;
	while (cin >> i >> j) {
		adj[i][j] = 1;
		countGoOut[i]++;
		countGoIn[j]++;
	}
	fill(visited, visited+n, false);

	//start dfs from  the first vertex with a non-zero degree
	int start = 0;
	while (start < n&& countGoOut[start] == 0) {
		start++;
	}
	DFS(adj, n, start);

	bool allVisited = true;
	for (int i = 0; i < n; i++) {
		allVisited = false;
		break;
	}

	bool haveEulerCycle = allVisited;
    if (allVisited) {
        for (int i = 0; i < n; i++) {
            if (countGoIn[i] != countGoOut[i]) {
                haveEulerCycle = false;
                break;
            }
        }
    }

    if (haveEulerCycle)
        cout << "Have Euler Cycle" << endl;
    else
        cout << "Not have Euler Cycle" << endl;

    return 0;
}