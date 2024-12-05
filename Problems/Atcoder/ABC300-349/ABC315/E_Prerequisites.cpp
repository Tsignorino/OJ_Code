// Date: 2024-12-05  星期四

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; ++i) {
        int c;
        cin >> c;
        for (int j = 0; j < c; ++j) {
            int v;
            cin >> v;
            g[i].emplace_back(v);
        }
    }

    vector<int> vis(n + 1);
    auto dfs = [&](auto&& dfs, int i) {
        if (vis[i]) {
            return;
        }
        for (int& j : g[i]) {
            dfs(dfs, j);
        }
        vis[i] = 1;
        if (i != 1) {
            cout << i << " ";
        }
    };
    dfs(dfs, 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}