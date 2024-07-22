/*
Consider the problem having weights and profits are:

Weights: {3, 4, 6, 5}

Profits: {2, 3, 1, 4}

The weight of the knapsack is 8 kg

The number of items is 4
*/

#include <bits/stdc++.h>
using namespace std;

int knap_sack(int C, int n, int W[], int V[]) {
	int table[n+1][C+1];
	for (int i = 0; i <= n; i++) {
		for (int w = 0; w <= C; w++) {
			if (i == 0 || w == 0) table[i][w] = 0;
			else if (W[i] <= w) {
				table[i][w] = max(V[i] + table[i-1][w - W[i]], table[i-1][w]);
			} else {
				table[i][w] = table[i-1][w];
			}
		}
	}
	return table[n][C];
}

int main()
{
	int C = 7;
	int n = 4;
	int W[4] = {1, 3, 4, 5};
	int V[4] = {1, 4, 5, 7};

	cout <<knap_sack(C, n, W, V);
	return 0;
}