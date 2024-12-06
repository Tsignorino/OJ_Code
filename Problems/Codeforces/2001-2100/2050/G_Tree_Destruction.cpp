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

    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vector<int> f(n);
    int ans = 1;
    auto dfs = [&](this auto&& dfs, int u, int pa = -1) -> void {
        int cnt = g[u].size() - 2;
        f[u] = cnt;
        ans = max(ans, cnt + 2);
        for (auto& v : g[u]) {
            if (v == pa) {
                continue;
            }
            dfs(v, u);
            ans = max(ans, f[u] + f[v] + 2);
            f[u] = max(f[u], cnt + f[v]);
        }
    };
    dfs(0);
    cout << ans << "\n";
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