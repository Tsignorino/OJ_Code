// Date: 2024-12-09  星期一

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vector<int> ans(n);
    int x = 1;
    auto dfs = [&](this auto&& dfs, int u, int pa = -1) -> void {
        ans[u] = x;

        int ok = 1;
        for (int& v : g[u]) {
            if (v == pa) {
                continue;
            }
            if (ok) {
                ok = 0;
                x++;
                dfs(v, u);
                x++; // 原路返回，增量为偶数
            } else {
                x += 2;
                dfs(v, u);
            }
        }
    };
    dfs(0);

    for (int& v : ans) {
        cout << v << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}