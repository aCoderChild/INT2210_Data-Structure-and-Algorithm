/* Say that you are a traveler on a 2D grid
You begin in the topleft corner and your goal is to travel to the bottom right corner.
you may only move down or right

In how many ways can you travel to the goal on a grid m x n
*/

//create key by using string variable type

#include <bits/stdc++.h>
using namespace std;

map<string, int> memo;

int gridTraveler(int m, int n) {
    string key = to_string(m) + "," + to_string(n);
    if (memo.find(key) != memo.end()) return memo[key];
    if (m == 0 || n == 0) return 0;
    if (m == 1 && n == 1) return 1;
    memo[key] = gridTraveler(m-1, n) + gridTraveler(m, n-1);
    return memo[key];
}

int main() {
    cout << "Enter the number of rows and columns of the grid: ";
    int m, n;
    cin >> m >> n;
    cout << "The number of ways to travel: ";
    cout << gridTraveler(m, n) << endl;
    return 0;
}

