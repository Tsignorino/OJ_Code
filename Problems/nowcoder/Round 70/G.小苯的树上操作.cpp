// Date: 2024-12-01  星期天

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vector f(2, vector<int>(n + 1));
    auto dfs = [&](auto&& dfs, int u, int pa) -> void {
        ll s1 = 0, s2 = 0, s = 0;
        for (int& v : g[u]) {
            if (v == pa) {
                continue;
            }
            dfs(dfs, v, u);
            ll val = f[1][v];
            if (val >= 0) {
                if (val > s1) {
                    s2 = s1;
                    s1 = val;
                } else if (val > s2) {
                    s2 = val;
                }
                s += val;
            }
        }
        f[0][u] = max(s1 + s2, a[u] + s);
        f[1][u] = max(s1, a[u] + s);
    };
    dfs(dfs, 1, -1);

    cout << ranges::max(f[0]) << "\n";
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