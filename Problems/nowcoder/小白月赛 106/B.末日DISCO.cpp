// Date: 2024-12-06  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> v(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cnt++;
            v[i].push_back(cnt);
            v[j].push_back(cnt);
        }
    }
    for (int i = 0; i < n; ++i) {
        cnt++;
        v[i].push_back(cnt);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << v[i][j] << " \n"[j == n - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}