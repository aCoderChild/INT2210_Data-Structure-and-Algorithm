#include <bits/stdc++.h>
using namespace std;
int main()
{
    double max = numeric_limits<double>::min();
    double min = numeric_limits<double>::max();

    double x;
    while (cin >> x) {
        if (x > max) max = x;
        if (x < min) min = x;
    }

    cout << max + min << endl;
    return 0;
}
