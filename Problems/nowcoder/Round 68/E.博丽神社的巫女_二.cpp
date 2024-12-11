// Date: 2024-12-11  星期三

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
        g[i].emplace_back(a[i]);
        while (g[i].back()) {
            g[i].emplace_back(g[i].back() / 2);
        }
    }

    const int S = 1e5;
    vector f(n + 1, vector<int>(S + 1, -1));
    f[0][0] = numeric_limits<int>::min();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= S; ++j) {
            if (f[i][j] != -1) {
                for (int& v : g[i]) {
                    if (j + v <= S) {
                        f[i + 1][j + v] = v;
                    }
                }
            }
        }
    }

    if (f[n].back() == -1) {
        cout << -1 << "\n";
        return;
    }

    int v = S;
    vector<int> ans(n, -1);
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < g[i].size(); ++j) {
            if (g[i][j] == f[i + 1][v]) {
                ans[i] = j;
                break;
            }
        }
        v -= f[i + 1][v];
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}