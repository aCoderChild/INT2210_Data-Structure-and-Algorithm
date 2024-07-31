//application of DFS and check connectivity
#include <bits/stdc++.h>
using namespace std;
#define V 6 // number of V from 0 to V-1
#define E 5 // number of edges

/* -- Algorithm --:
Implement the idea:
1. Remove edge (u, v) from the graph
2. see if the graph remains connected (using DFS)
3. Add(u, v) back to the grpah

Complexity: O(E * (V+E))
Auxilary Space: O(E+V)
*/