#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10001;

bool Prime[MAX_N];

void prime() {
    memset(Prime, true, sizeof(Prime));
    Prime[0] = false;
    Prime[1] = false;
    for (int i = 2; i * i <= MAX_N; i++) {
        if (Prime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                Prime[j] = false;
            }
        }
    }
}

int findPrime(int q) {
    prime();
    int count = 0;
    for (int i = 2; i <= MAX_N; i++) {
        if (Prime[i]) {
            count++;
            if (count == q) return i;
        }
    }
    return -1;
}

void solve(vector<int>& v, int q) {
    if (q == 0) return;

    int t = findPrime(q);
    vector<int> stackA, stackB;
    for (auto j : v) {
        if (j % t == 0) stackB.push_back(j);
        else stackA.push_back(j);
    }

    v.clear();
    for (int j = stackB.size() - 1; j >= 0; j--) {
        v.push_back(j);
    }
    for (int j = stackA.size() - 1; j >= 0; j--) {
        v.push_back(j);
    }

    solve(v, q - 1);
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);

    int q = 3;

    solve(v, q);

    for (auto i : v) {
        cout << i << " ";
    }

    return 0;
}