//Analyse: start counting from vector[0]


#include <bits/stdc++.h>
using namespace std;

bool check(int X, vector<int>& A, int n, int current_sum = 0, int index = 0) {
    if (current_sum == X) return true;
    if (current_sum > X || index == n) return false;

    return check(X, A, n, current_sum + A[index], index + 1)|| 
           check(X, A, n, current_sum, index + 1);
}

int main()
{
    cout << "Enter n and X: ";
    int n, X;
    cin >> n >> X;

    vector<int> A;
    cout << "Enter the ages of students: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A.push_back(x);
    }

    if(check(X, A, n)) cout << "YES";
    else cout << "NO";
    return 0;
}