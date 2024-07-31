//find the number of graphs with V vertices and E edges
#include <bits/stdc++.h>
using namespace std;

//function to calculate binomial coefficients C(n, k)
unsigned long long Binomial_Coeffiecient(int n, int k) {
	if (k > n - k) {
		k = n - k;
	}

	//apply the formula: nCk = n! / (k!)(n-k)!
	unsigned long long res = 1;
	for (int i = 0; i < k; i++) {
		res *= (n-i);
		res /= (i+1);
	}
	return res;
}

unsigned long long countGraphs(int V, int E) {
	int maxEdges = (V * (V-1) / 2);
	return Binomial_Coeffiecient(maxEdges, E);
} 

int main()
{
	int V, E;
	cout << "Enter the number of vertices (V) and edges(E): ";
	cin >> V >> E;
	if (E > (V * (V-1) / 2)) {
		cout << "Number of edges exceeds the maximum number of possible edges!";
		return 1;
	}

	unsigned long long Number_Of_Graphs = countGraphs(V, E);
	cout << "number of different undirected graphs: " << Number_Of_Graphs << endl;
	return 0;
}