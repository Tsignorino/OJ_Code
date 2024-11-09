#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> pa(n + 1), _size(n + 1, 1);
    auto dfs = [&](this auto&& dfs, int u, int p) -> void {
        pa[u] = p;
        for (int& v : g[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
            _size[u] += _size[v];
        }
    };
    dfs(x, -1);

    ll res = _size[y];
    while (pa[y] != x) {
        y = pa[y];
    }
    res *= n - _size[y];
    cout << n * 1ll * (n - 1) - res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}