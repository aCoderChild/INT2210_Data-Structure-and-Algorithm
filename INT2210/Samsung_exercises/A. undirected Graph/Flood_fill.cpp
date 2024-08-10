#include <bits/stdc++.h>
using namespace std;

#define M 8
#define N 8

void Flood_Fill_DFS(int A[][N], const int y, const int x, const int targetVal, const int newVal) { //using recursive
	if (y < 0 || y >= M) {
		return;
	}
	if (x < 0 || x >= N) {
		return;
	}
	if (A[y][x] != targetVal) {
		return;
	}
	A[y][x] = newVal;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			Flood_Fill_DFS(A, y+i, x+i, targetVal, newVal);
		}
	}
}

void Flood_Fill_BFS(int A[][N], const int y, const int x, const int targetVal, const int newVal) {
	queue<int> qy;
	queue<int> qx;

	while(!qx.empty() && !qy.empty()) {
		const int y = qy.front();
		qy.pop();
		const int x = qx.front();
		qx.pop();

		if (y < 0 || x < 0 || y >= M || x >= N || A[y][x] != targetVal) {
			continue;
		}
		A[x][y] = newVal;

		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				qy.push(y+i);
				qx.push(x+j);
			}
		}
	}
}

void printArray(int A[][N]) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int image[M][N] = {
        {3, 2, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 0},
        {1, 0, 0, 1, 1, 0, 1, 1},
        {1, 2, 2, 2, 2, 0, 1, 0},
        {1, 1, 1, 2, 2, 0, 1, 0},
        {1, 1, 1, 2, 2, 2, 2, 0},
        {1, 1, 1, 1, 1, 2, 1, 1},
        {1, 1, 1, 1, 1, 2, 2, 1},
    };

    const int y = 0;
    const int x = 2;
    const int targetColor = image[y][x];
    const int newColor = 9;

    cout << "Before" << endl;
    printArray(image);

    Flood_Fill_BFS(image, y, x, targetColor, newColor);

    cout << endl;
    cout << "After" << endl;
    printArray(image);


    return 0;

}


