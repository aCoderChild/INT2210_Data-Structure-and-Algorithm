#include <bits/stdc++.h>
using namespace std;
/*
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int res = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && a[i] == a[j]) res++;
        }
    }

    cout << res/2 << endl;
    return 0;
}
*/

//using Map - count the pairs
int count (int a[], int n) {
    map<int, int> cnt;
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += cnt[a[i]];
        cnt[a[i]]++;
        //res += cnt[a[i]];
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << count(a, n) << endl;
    return 0;
}
