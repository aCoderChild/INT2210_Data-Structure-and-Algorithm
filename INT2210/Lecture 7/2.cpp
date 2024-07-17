#include <bits/stdc++.h>
using namespace std;

void maxMatrixSum (vector<vector<int> >& matrix) {
	int n = matrix.size();
	int m = matrix[0].size();

	int maxsum = INT_MIN;
	int top = 0, bottom = 0, left = 0, right = 0;

	//loop for top row position in the rectangle
	for (int i = 0; i < n; i++) {
		//loop for the left column position of the rectangle
		for (int j = 0; j < m; j++) {
			//loop for the bottom row in the rectangle
			for (int k = 0; k < n; k++) {
				//loop for the right column of the rectangle
				for (int l = 0; l < m; l++) {
					int curr = 0;
					for (int x = i; x <= k; x++) {
						for (int y = j; y <= l; y++) {
							curr += matrix[x][y];
						}
					}

					if (curr > maxsum) {
						maxsum = curr;
						top = i;
						left = j;
						right = k;
						bottom = l;
					}
				}
			}
		}
	}

	cout << "(Top, left): " << "(" << top << ", " << left << ")" << endl;
	cout << "(Bottom, right): " << "(" << bottom << ", " << right << ")" << endl;
}

int main()
{
	vector<vector<int> > v;
	v.push_back({-1, -1, -1, -1, 2}); 
	v.push_back({-1, 2, -2, 1, 3}); 
	v.push_back({2, -1, -1, -1, -1}); 
	maxMatrixSum(v);
	return 0;
}